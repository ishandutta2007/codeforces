/*
 * author:  ADMathNoob
 * created: 07/22/21 10:35:08
 * problem: https://codeforces.com/contest/1553/problem/F
 */

/*
g++ 1553F.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1553F.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

const int A = 300005;

int n;
vector<int> a;

vector<long long> res;

void Solve(int L, int R) {
  if (L == R) {
    return;
  }
  int M = (L + R) / 2;
  Solve(L, M);
  Solve(M + 1, R);
  
  const int cntL = M - L + 1;
  const int cntR = R - M;

  {
    // left is smaller
    vector<int> ids(cntR);
    iota(ids.begin(), ids.end(), M + 1);
    sort(ids.begin(), ids.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    vector<int> sortedR(cntR);
    for (int i = 0; i < cntR; i++) {
      sortedR[i] = a[ids[i]];
    }
    vector<long long> add(cntR + 1);
    for (int i = L; i <= M; i++) {
      for (int x = a[i]; x < A; x += a[i]) {
        int j = (int) (lower_bound(sortedR.begin(), sortedR.end(), x) - sortedR.begin());
        add[j] -= a[i];
        add[cntR] += a[i];
      }
    }
    for (int i = 0; i < cntR; i++) {
      add[i + 1] += add[i];
      res[ids[i]] += add[i];
    }
    // debug(L, M, R, sortedR, add);
  }
  {
    // right is smaller
    vector<long long> add(cntR);
    vector<int> sortedL(a.begin() + L, a.begin() + M + 1);
    sort(sortedL.begin(), sortedL.end());
    for (int i = M + 1; i <= R; i++) {
      for (int x = a[i]; x < A; x += a[i]) {
        int j = (int) (lower_bound(sortedL.begin(), sortedL.end(), x) - sortedL.begin());
        res[i] -= (long long) a[i] * (cntL - j);
      }
    }
  }
  
  long long sumL = 0;
  for (int i = L; i <= M; i++) {
    sumL += a[i];
  }
  for (int i = M + 1; i <= R; i++) {
    res[i] += sumL + (long long) (M - L + 1) * a[i];
  }
  // debug(res);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  res.resize(n);
  Solve(0, n - 1);
  for (int i = 0; i < n - 1; i++) {
    res[i + 1] += res[i];
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << res[i];
  }
  cout << '\n';
  return 0;
}