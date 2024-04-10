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
  int n; cin >> n;
  int curpart = 0;
  int L = 1;
  int R = n;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    //  M -> 0
    int ask = n - M;
    cout << "+ " << ask << endl;
    int resp; cin >> resp;
    if (resp > curpart) {
      assert(resp == curpart + 1);
      int nL = 0;
      int nR = R - M;
      L = nL;
      R = nR;
    } else {
      R = M;
      L += ask;
      R += ask;
    }
    curpart = resp;
  }
  assert(L + 1 == R);
  cout << "! " << L + curpart * n << endl;
  return 0;
}