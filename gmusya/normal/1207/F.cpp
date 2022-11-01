#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const int K = 750;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <ll> a(500001);
  vector <vector <ll>> arr(K, vector<ll>(K));
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int pos, val;
      cin >> pos >> val;
      a[pos] += val;
      for (int i = 1; i < K; i++)
        arr[i][pos % i] += val;
    }
    if (t == 2) {
      int x, y;
      cin >> x >> y;
      ll res = 0;
      if (x >= K) {
        for (int i = y; i <= 500000; i += x)
          res += a[i];
      } else {
        res = arr[x][y];
      }
      cout << res << '\n';
    }
  }
  return 0;
}