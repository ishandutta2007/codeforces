#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#define debug(x) cerr << #x << ": <" << (x) << ">\n"
#else
#define debug(x)
#endif
}

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  cin.ignore(87, '\n');
  string s; cin >> s;
  vector<int> freq(10);
  for (char& c : s) {
    int i = c - '0';
    while (i)
      freq[i--]++;
  }

  for (int i = 9; i > 1; i--) {
    int cur = i;
    for (int j = 2; j < i && cur != 1; j++) {
      while (cur % j == 0) {
        cur /= j;
        freq[j] += freq[i];
      }
    }

    if (cur == 1)
      continue;

    while (freq[i]) {
      cout << i;
      for (int j = i; j > 1; j--)
        freq[j]--;
    }
  }

  return 0;
}