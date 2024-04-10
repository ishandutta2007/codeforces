// August 27, 2020
// https://codeforces.com/contest/1039/problem/B

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors FILENAME.cpp
*/


#include <bits/stdc++.h>

using namespace std;


int q = 4500;

bool ask(long long l, long long r) {
  assert(--q >= 0);
  cout << l << ' ' << r << endl;
  string res;
  cin >> res;
  if (l == r && res[0] == 'Y') {
    exit(0);
  }
  return (res[0] == 'Y');
}

int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
  
// #ifdef _DEBUG
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
//   freopen("debug_output.txt", "w", stderr);
// #endif
  

  srand(12345678);
  
  long long n;
  int k;
  cin >> n >> k;
  long long low = 1, high = n;
  while (true) {
    long long mid = (low + high) >> 1;
    if (high - low + 1 > 4 * k + 1) {
      if (ask(low, mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    } else {
      long long guess = low + (rand() % (high - low + 1));
      ask(guess, guess);
    }
    low = max(low - k, 1LL);
    high = min(high + k, n);
  }
  
  
  return 0;
}