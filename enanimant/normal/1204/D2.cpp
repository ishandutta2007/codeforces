// August 20, 2019
// https://codeforces.com/contest/1204/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 100005;


int n;
int s[N];
int psa[N];
int lis[N]; // lis of s[i...n]
bool no_zeroes[N];

int ones(int ll, int rr) {
  return psa[rr + 1] - psa[ll];
}

int zeroes(int ll, int rr) {
  int len = rr - ll + 1;
  return len - ones(ll, rr);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  string tmp;
  cin >> tmp;
  n = (int) tmp.size();
  psa[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i] = tmp[i] - '0';
    psa[i + 1] = psa[i] + s[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 0) {
      lis[i] = lis[i + 1] + 1;
    } else {
      lis[i] = lis[i + 1];
      if (ones(i, n - 1) > lis[i + 1]) {
        lis[i] = ones(i, n - 1);
        no_zeroes[i] = true;
      }
    }
  }
  int cnt = 0; // number of 0s so far
  for (int i = 0; i < n; i++) {
    if (s[i] == 0) {
      cnt++;
      cout << 0;
      continue;
    }
    if (no_zeroes[i] && cnt + lis[i] == lis[0]) {
      cnt++;
      cout << 0;
    } else {
      cout << 1;
    }
  }
  cout << '\n';


  return 0;
}