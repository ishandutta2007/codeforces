#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct student {
  student(int _b = 0, int _c = 0, int _index = 0) : b(_b), c(_c), index(_index) {};
  int b, c, index;
};

bool operator < (const student& a, const student& b) {
  return a.b < b.b;
}

int n, m, s;
vector<pair<int, int> > bugs;
vector<student> st;
set<pair<int, int> > f;
int ans[100005];

bool solve(int d) {
  f.clear();
  int sum = 0;
  memset(ans, -1, sizeof(ans));
  int pnt = st.size() - 1;
  for (int i = 0; i < bugs.size(); i += d) {
    int cur = i;
    for (;pnt >= 0; --pnt) {
      if (st[pnt].b >= bugs[cur].first) {
        f.insert(make_pair(st[pnt].c, pnt));
      } else {
        break;
      }
    }
    if (f.size()) {
      sum += st[f.begin()->second].c;
    }
    if (f.empty() || sum > s) {
      return false;
    }
    int ind = st[f.begin()->second].index + 1;
    for (int j = i; j < i + d && j < bugs.size(); ++j) {
      ans[bugs[j].second] = ind;
    }
    f.erase(f.begin());
  }
  return true;
}

int main() {
  scanf("%d%d%d", &n, &m, &s);
  bugs.resize(m); st.resize(n);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &bugs[i].first);
    bugs[i].second = i;
  }
  sort(bugs.rbegin(), bugs.rend());
  for (int i = 0; i < n; ++i) {
    scanf("%d", &st[i].b);
    st[i].index = i;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &st[i].c);
  }
  sort(st.begin(), st.end());
  int l = 0, r = m + 1;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (solve(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (r == m + 1) {
    puts("NO");
  } else {
    puts("YES");
    // cout << r << endl;
    solve(r);
    for (int i = 0; i < m; ++i) {
      if (i) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}