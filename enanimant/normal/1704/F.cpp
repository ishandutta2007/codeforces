/*
 * author:  ADMathNoob
 * created: 07/31/22 07:05:08
 * problem: https://codeforces.com/contest/1704/problem/F
 */

/*
Comments about problem:

Here's a problem:

Let S denote the set of non-negative integers.

Let g : 2^S -> S and h : S x S -> S.

We have a function f : S -> S of the form:

def f(n):
  A = empty set
  for i from 0 to n-m:
    insert h(f(i), f(n-m-i)) into A
  return g(A)

We want to check if f is periodic with start s and period p. How far do we have to check
the function f for periodicity starting from s?

In this problem, g = mex and h = xor.
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

int Mex(vector<int> a) {
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
  int n = a.size();
  for (int i = 0; i < n; i++) {
    if (a[i] != i) {
      return i;
    }
  }
  return n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  const int N = 1234;
  vector<int> sg(N);
  sg[0] = 0;
  for (int i = 1; i < N; i++) {
    vector<int> a;
    for (int j = 0; j <= i - 2; j++) {
      a.push_back(sg[j] ^ sg[i - 2 - j]);
    }
    sg[i] = Mex(a);
  }
  {
    auto HasPeriod = [&](vector<int> a, int p) {
      int n = a.size();
      for (int i = 0; i + p < n; i++) {
        if (a[i] != a[i + p]) {
          return false;
        }
      }
      return true;
    };
    
    [&] {
      for (int p = 1; p <= N / 2; p++) {
        for (int start = 0; start < N / 2; start++) {
          vector<int> b(sg.begin() + start, sg.end());
          if (HasPeriod(b, p)) {
            debug(start, p);
            return;
          }
        }
      }
    }();
  }
  const int P = 34;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int kr = 0, kb = 0;
    for (char c : s) {
      if (c == 'R') {
        kr += 1;
      } else {
        kb += 1;
      }
    }
    if (kr > kb) {
      cout << "Alice" << '\n';
      continue;
    }
    if (kr < kb) {
      cout << "Bob" << '\n';
      continue;
    }
    int x = 0;
    int beg = 0;
    while (beg < n) {
      int end = beg;
      while (end + 1 < n && s[end + 1] != s[end]) {
        ++end;
      }
      int len = end - beg + 1;
      if (len >= N) {
        len = (len - N) % P + N - P;
      }
      x ^= sg[len];
      beg = end + 1;
    }
    cout << (x == 0 ? "Bob" : "Alice") << '\n';
  }
  return 0;
}