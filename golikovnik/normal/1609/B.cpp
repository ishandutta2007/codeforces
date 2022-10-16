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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  set<int> st;
  string s; cin >> s;

  auto add = [&](int at) {
    if (at < 0 || at >= n - 2) return;
    if (s.substr(at, 3) == "abc") st.insert(at);
  };
  auto rem = [&](int at) {
    if (at < 0 || at >= n - 2) return;
    if (s.substr(at, 3) == "abc") st.erase(at);
  };


  for (int i = 0; i < n; ++i) {
    add(i);
  }
  while (q--) {
    int pos; char ch; cin >> pos >> ch; --pos;
    for (int i = -2; i <= 2; ++i) {
      rem(pos + i);
    }
    s[pos] = ch;
    for (int i = -2; i <= 2; ++i) {
      add(pos + i);
    }
    cout << st.size() << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}