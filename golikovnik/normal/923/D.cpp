//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

tuple<string, string, vector<int>, vector<int>, vector<int>> read() {
  string s; cin >> s;
  int n = int(s.size());
  vector<int> id(n);
  string ans;
  int nc = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A' || s[i] == 'B') {
      id[i] = i + nc;
      ans.push_back(s[i]);
      continue;
    }
    id[i] = i + nc++;
    ans.push_back('A');
    ans.push_back('B');
  }
  int len = int(ans.size());
  vector<int> prevb(len, -1);
  for (int i = 0; i < len; ++i) {
    if (i > 0) {
      prevb[i] = prevb[i - 1];
    }
    if (ans[i] == 'B') {
      prevb[i] = i;
    }
  }
  vector<int> prefb(len + 1);
  for (int i = 0; i < len; ++i) {
    prefb[i + 1] = prefb[i] + (ans[i] == 'B');
  }

  return make_tuple(ans, s, id, prevb, prefb);
}

pair<int, int> mk(int l, int r, string& is, vector<int>& ids, vector<int>& prevb, vector<int>& prefb) {
  l = ids[l];
  r = ids[r] + (is[r] == 'C');
  return make_pair(prefb[r + 1] - prefb[l], r - max(l - 1, prevb[r]));
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto[s, is, ids, prevbs, prefbs] = read();
  auto[t, it, idt, prevbt, prefbt] = read();

  int q; cin >> q;
  while (q--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    --l1, --r1, --l2, --r2;
    auto[xl, yl] = mk(l1, r1, is, ids, prevbs, prefbs);
    auto[xr, yr] = mk(l2, r2, it, idt, prevbt, prefbt);
    if (xl == xr) {
      cout << (yr <= yl && yl % 3 == yr % 3);
    } else {
      if (xl == 0) {
        --yl;
      }
      cout << (xl <= xr && xl % 2 == xr % 2 && yr <= yl);  
    }
  }
  cout << '\n';  

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}