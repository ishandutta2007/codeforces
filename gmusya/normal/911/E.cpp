#pragma GCC optimize("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef vector <int> vi;

bool flag = true;
int n, k;
vi pref;

void solve(int l, int r, int lpos, int rpos, int &it) {
  if (l > r)
    return;
  if (!flag)
    return;
  if (it == k + 1) {
    for (int i = l; i <= r; i++)
      pref[i - l + lpos] = r + l - i;
    return;
  }
  if (r < pref[it] || pref[it] < l) {
    if (!flag)
      return;
    flag = false;
    cout << -1 << endl;
    return;
  }
  int val = pref[it];
  it++;
  solve(l, val - 1, lpos + 1, lpos + (val - l), it);
  if (!flag)
    return;
  solve(val + 1, r, lpos + (val - l) + 1, rpos, it);
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  pref.resize(n + 1);
  for (int i = 1; i <= k; i++)
    cin >> pref[i];
  int it = 1;
  solve(1, n, 1, n, it);
  if (!flag)
    return 0;
  for (int i = 1; i <= n; i++)
    cout << pref[i] << ' ';
  return 0;
}