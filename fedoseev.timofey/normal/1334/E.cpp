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

const int md = 998244353;

void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

int mul(int a, int b) {
  return ((ll)a * b) % md;
}

const int N = 100;
const int Inf = 1e9;
int C[N][N];
int f[N];

void init() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      add(C[i][j], C[i - 1][j - 1]);
      add(C[i][j], C[i - 1][j]);
    }
  }
  f[0] = 1;
  for (int i = 1; i < N; ++i) f[i] = mul(f[i - 1], i);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  init();
  ll D;
  cin >> D;
  vector <ll> pr;
  {
    ll x = D;
    for (ll d = 2; d * d <= D; ++d) {
      if (x % d == 0) {
        pr.push_back(d);
        while (x % d == 0) x /= d;
      }
    }
    if (x > 1) pr.push_back(x);
    sort(pr.begin(), pr.end());
  }
  int n = pr.size();
  int q;
  cin >> q;
  while (q--) {
    ll u, v;
    cin >> u >> v;
    vector <int> cu, cv;
    {
      ll tu = u, tv = v;
      for (int i = 0; i < n; ++i) {
        cu.push_back(0);
        cv.push_back(0);
        while (tu % pr[i] == 0) {
          ++cu.back();
          tu /= pr[i];
        }
        while (tv % pr[i] == 0) {
          ++cv.back();
          tv /= pr[i];
        }
      }
    }

    int ans = 1;
    vector <int> have;
    for (int i = 0; i < n; ++i) {
      if (cu[i] > cv[i]) have.push_back(cu[i] - cv[i]);
    }
    int sum = 0;
    for (int x : have) sum += x;
    for (int x : have) {
      ans = mul(ans, C[sum][x]);
      sum -= x;
    } 

    have.clear();

    for (int i = 0; i < n; ++i) {
      if (cu[i] < cv[i]) have.push_back(cv[i] - cu[i]);
    }
    sum = 0;
    for (int x : have) sum += x;
    for (int x : have) {
      ans = mul(ans, C[sum][x]);
      sum -= x;
    } 

    cout << ans << '\n';
  }
}