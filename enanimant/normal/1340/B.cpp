// April 23, 2020
// https://codeforces.com/contest/1340/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 2005;

string STRS[10] = {
  "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

bool can_get_digit[1 << 7][8];
bool dp[N][N];

bool can(int d, int flips) {
  if (flips >= 8) {
    return false;
  }
  return can_get_digit[d][flips];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  for (int j = 0; j < 10; j++) {
    int x = stoi(STRS[j], nullptr, 2);
    for (int i = 0; i < (1 << 7); i++) {
      if ((i & x) == i) {
        int flips = __builtin_popcount(i ^ x);
        can_get_digit[i][flips] = true;
      }
    }
  }

  int n, k;
  cin >> n >> k;
  vector<int> digits(n);
  for (int i = 0; i < n; i++) {
    string d;
    cin >> d;
    digits[i] = stoi(d, nullptr, 2);
  }
  dp[n][0] = true;
  for (int i = n - 1; i >= 0; i--) {
    int d = digits[i];
    for (int j = 0; j <= k; j++) {
      for (int f = 0; f <= 7; f++) {
        if (j - f < 0) {
          continue;
        }
        if (can(d, f)) {
          dp[i][j] |= dp[i + 1][j - f];
        }
      }
    }
  }
  int cur = k;
  for (int i = 0; i < n; i++) {
    int d = digits[i];
    bool ok = false;
    for (int j = 9; j >= 0; j--) {
      int x = stoi(STRS[j], nullptr, 2);
      int f = __builtin_popcount(d ^ x);
      if ((d & x) == d && dp[i + 1][cur - f]) {
        cur -= f;
        cout << j;
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "-1\n";
      return 0;
    }
  }
  cout << '\n';


  return 0;
}