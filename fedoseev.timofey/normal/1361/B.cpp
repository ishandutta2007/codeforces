#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int md = 1e9 + 7;

const int N = 1e6 + 7;

int cnt[N];

int mul(int a, int b) {
  return ((ll)a * b) % md;
}

int power(int a, ll b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

const int Inf = 1e9;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n >> p;
    vector <int> k(n);
    for (int i = 0; i < n; ++i) {
      cin >> k[i];
      ++cnt[k[i]];
    }
    vector <int> c = k;
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    reverse(c.begin(), c.end());
    int ans = 0;
    int pw = 0;
    int lst = -1;
    for (int x : c) {
      if (pw > 0) {
        if (p > 1) {
          while (lst > x && pw != Inf) {
            pw = min((ll)Inf, (ll)pw * p);
            --lst;
          }
        }
        while (cnt[x] > pw) {
          cnt[x] -= 2;
        }
        sub(ans, mul(cnt[x], power(p, x)));
        pw -= cnt[x];
      } else {
        if (cnt[x] % 2 == 1) {
          add(ans, power(p, x));
          pw = 1;
        }
      }
      lst = x;
      cnt[x] = 0;
    }
    cout << ans << '\n';
  }
}