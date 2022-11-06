#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct form_t {
  lint a = 0LL; /* *t */
  lint b = 0LL;
  lint x() const { return a; }
  lint y() const { return b; }
  lint eval(lint t) const {
    return a * t + b;
  }
};

form_t operator+(const form_t &l, const form_t &r) {
  return {l.a + r.a, l.b + r.b};
}

form_t operator-(const form_t &l, const form_t &r) {
  return {l.a - r.a, l.b - r.b};
}

lint cross(const form_t &a, const form_t &b) {
  return a.x() * b.y() - a.y() * b.x();
}

lint cross(const form_t &a, const form_t &b, const form_t &c) {
  return cross(b - a, c - a);
}

struct edge_t {
  int o;
  form_t f;
};

struct solver_t {
  vector<vector<edge_t>> adj;
  int m;
  //
  int n = adj.size();
  vector<int> sts = vector<int>(n);
  vector<bool> removed = vector<bool>(n, false);

  vector<form_t> cands;

  void calc_sts(int v, int p) {
    sts[v] = 1;
    for (edge_t &ed : adj[v])
      if (!removed[ed.o] && ed.o != p) {
        calc_sts(ed.o, v);
        sts[v] += sts[ed.o];
      }
  }

  int get_centroid(int v, int p, int root_sts) {
    for (edge_t &ed : adj[v])
      if (!removed[ed.o] && ed.o != p && 2 * sts[ed.o] > root_sts)
        return get_centroid(ed.o, v, root_sts);
    return v;
  }

  void get_forms(int v, int p, form_t f, vector<form_t> &output) {
    bool is_leaf = true;
    for (edge_t &ed : adj[v])
      if (!removed[ed.o] && ed.o != p) {
        is_leaf = false;
        get_forms(ed.o, v, f + ed.f, output);
      }
    if (is_leaf)
      output.push_back(f);
  }

  void keep_maximal(vector<form_t> &forms) {
    sort(forms.begin(), forms.end(),
         [](const form_t &lhs, const form_t &rhs) {
           if (lhs.a != rhs.a)
             return lhs.a < rhs.a;
           return lhs.b > rhs.b;
         });

    int new_size = 0;
    for (int i = 0; i < (int)forms.size(); ++i)
      if (new_size == 0 || forms[i].a > forms[new_size - 1].a)
        forms[new_size++] = forms[i];
    forms.resize(new_size);

    new_size = 0;
    for (int i = 0; i < (int)forms.size(); ++i) {
      while (new_size > 0 && forms[i].b >= forms[new_size - 1].b)
        --new_size;
      forms[new_size++] = forms[i];
    }
    forms.resize(new_size);

    vector<form_t> result;
    for (const form_t f : forms) {
      while ((int)result.size() >= 2 &&
             cross(f, result.end()[-2], result.end()[-1]) >= 0LL)
        result.pop_back();
      result.push_back(f);
    }
    forms = result;
  }

  vector<pair<form_t, pair<lint, lint>>>
  form_and_ranges(const vector<form_t> &forms) {
    vector<pair<form_t, pair<lint, lint>>> result(forms.size());
    for (int i = 0; i < (int)forms.size(); ++i) {
      result[i].first = forms[i];
      pair<lint, lint> &range = result[i].second;

      if (i == 0) range.first = 0;
      else range.first = result[i - 1].second.second;

      if (i + 1 < (int)forms.size()) {
        const form_t me = forms[i];
        const form_t next = forms[i + 1];

        lint up = me.b - next.b;
        lint down = next.a - me.a;
        lint t = up / down;

        range.second = min((lint)m - 1, t);
      } else {
        range.second = m - 1;
      }
    }
    return result;
  }

  void add_pairs(vector<pair<form_t, pair<lint, lint>>> &a,
                 vector<pair<form_t, pair<lint, lint>>> &b) {
    int j = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
      while (j < (int)b.size() &&
             b[j].second.second < a[i].second.first) ++j;
      for (int k = j;
           k < (int)b.size() &&
             b[k].second.first <= a[i].second.second; ++k) {
        form_t f = a[i].first + b[k].first;
        cands.push_back(f);
      }
    }
  }

  void solve_c(int c) {
    vector<vector<form_t>> formss;
    for (edge_t &ed : adj[c])
      if (!removed[ed.o]) {
        vector<form_t> forms_u;
        get_forms(ed.o, c, ed.f, forms_u);
        formss.push_back(move(forms_u));
      }

    vector<vector<pair<form_t, pair<lint, lint>>>> frs;

    for (vector<form_t> &forms : formss) {
      keep_maximal(forms);
      frs.push_back(form_and_ranges(forms));
      for (form_t f : forms)
        cands.push_back(f);
    }

    for (int i = 0; i < (int)formss.size(); ++i)
      for (int j = i + 1; j < (int)formss.size(); ++j) {
        add_pairs(frs[i], frs[j]);
      }
  }

  void solve(int v) {
    calc_sts(v, -1);
    int c = get_centroid(v, -1, sts[v]);
    solve_c(c);

    removed[c] = true;
    for (edge_t &ed : adj[c])
      if (!removed[ed.o])
        solve(ed.o);
  }

  void solve() {
    for (int i = 0; i < n; ++i)
      assert((int)adj[i].size() <= 3);
    solve(0);

    cands.push_back(form_t());
    keep_maximal(cands);

    int i = 0;
    for (int t = 0; t < m; ++t) {
      while (i + 1 < (int)cands.size() &&
             cands[i + 1].eval(t) > cands[i].eval(t)) {
        ++i;
      }
      if (t > 0) printf(" ");
      printf("%lld", cands[i].eval(t));
    }
    printf("\n");
  }
};

int expand(int v, int p, const vector<vector<edge_t>> &adj,
           vector<vector<edge_t>> &adj2) {
  int new_v = adj2.size();
  adj2.push_back({});

  vector<pair<int, form_t>> children;
  for (const edge_t &ed : adj[v])
    if (ed.o != p)
      children.emplace_back(expand(ed.o, v, adj, adj2), ed.f);

  while ((int)children.size() > 2) {
    pair<int, form_t> ca = children.back();
    children.pop_back();
    pair<int, form_t> cb = children.back();
    children.pop_back();

    int join = adj2.size();
    adj2.push_back({});

    adj2[join].push_back({ca.first, ca.second});
    adj2[ca.first].push_back({join, ca.second});

    adj2[join].push_back({cb.first, cb.second});
    adj2[cb.first].push_back({join, cb.second});

    children.emplace_back(join, form_t());
  }

  for (const pair<int, form_t> &child : children) {
    adj2[new_v].push_back({child.first, child.second});
    adj2[child.first].push_back({new_v, child.second});
  }

  return new_v;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<edge_t>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v), --u, --v;
    int a, b;
    scanf("%d %d", &a, &b);
    form_t f = {(lint)a, (lint)b};
    adj[u].push_back({v, f});
    adj[v].push_back({u, f});
  }

  vector<vector<edge_t>> adj2;
  expand(0, -1, adj, adj2);

  solver_t solver{adj2, m};
  solver.solve();

  return 0;
}