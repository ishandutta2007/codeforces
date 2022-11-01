/*
 * author:  ADMathNoob
 * created: 10/15/22 10:35:12
 * problem: https://codeforces.com/contest/1746/problem/E1
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../.cp/algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

// #ifdef _DEBUG
#if 0

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int RandInt(int low, int high) {
  return low + (rng() % (high - low + 1));
}

bool Ask(const vector<int>& a) {
  return RandInt(0, 1);
}

bool Answer(int x) {
  return true;
}

#else

bool Ask(const vector<int>& a) {
  cout << "? " << a.size();
  for (int x : a) cout << ' ' << x + 1;
  cout << endl;
  string s;
  cin >> s;
  return s == "YES";
}

bool Answer(int x) {
  cout << "! " << x + 1 << endl;
  string s;
  cin >> s;
  return s == ":)";
}

#endif

void TestCase(int n) {
  vector<int> s(n);
  iota(s.begin(), s.end(), 0);
  int iters = 0;
  while ((int) s.size() > 3) {
    assert(++iters < 100);
    int m = s.size();
    vector<int> A, B, C;
    vector<int> Ac, Bc, Cc;
    for (int i = 0; i < m; i++) {
      if (i % 2 < 1) {
        A.push_back(s[i]);
      } else {
        Ac.push_back(s[i]);
      }
      
      if (i % 4 < 2) {
        B.push_back(s[i]);
      } else {
        Bc.push_back(s[i]);
      }
      
      if (i % 8 < 4) {
        C.push_back(s[i]);
      } else {
        Cc.push_back(s[i]);
      }
    }

    if (!Ask(A)) {
      swap(A, Ac);
    }
    if (!Ask(B)) {
      swap(B, Bc);
    }
    if (!Ask(C)) {
      swap(C, Cc);
    }
    
    s = B;
    set_intersection(A.begin(), A.end(), C.begin(), C.end(), back_inserter(s));
    sort(s.begin(), s.end());
    s.resize(unique(s.begin(), s.end()) - s.begin());
    // debug(m, s);
    assert((int) s.size() < m);
  }
  if ((int) s.size() <= 2) {
    for (int x : s) {
      if (Answer(x)) {
        return;
      }
    }
    assert(0);
  }
  
  bool r0 = Ask({s[0]});
  if (r0) {
    if (Answer(s[0])) return;
    // next response is the truth
    bool is_s1 = Ask({s[1]});
    if (is_s1) Answer(s[1]);
    else Answer(s[2]);
    return;
  }
  
  bool r0_again = Ask({s[0]});
  if (!r0_again) {
    // not s[0] twice in a row, so it's either s[1] or s[2]
    if (!Answer(s[1])) Answer(s[2]);
    return;
  }
  
  if (Answer(s[0])) return;
  // next response is the truth
  bool is_s1 = Ask({s[1]});
  if (is_s1) Answer(s[1]);
  else Answer(s[2]);
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // {
  //   for (int it = 0; it < 10; it++) {
  //     for (int i = 4; i <= 20; i++) {
  //       TestCase(i);
  //     }
  //   }
  //   return 0;
  // }
  int n;
  cin >> n;
  TestCase(n);
  return 0;
}