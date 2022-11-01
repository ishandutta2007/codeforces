#include <iostream>
#include <vector>

typedef __int128 ll;

using namespace std;

const ll MOD = 998244353;

int count_zn(ll val) {
  int ans = 0;
  while (val) {
    val /= 10;
    ans++;
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; i++) {
  	long long x;
  	cin >> x;
    a[i] = x;
  }
  vector <ll> p10(30);
  p10[0] = 1;
  for (int i = 1; i < 30; i++)
    p10[i] = p10[i - 1] * 10;
  vector <int> zn(n), cnt(30);
  for (int i = 0; i < n; i++) {
    zn[i] = count_zn(a[i]);
    cnt[zn[i]]++;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < 30; j++) {
      cnt[zn[i]]--;
      ll sum = 0;
      int it = 0;
      for (int x = 0; x < zn[i]; x++) {
        sum += p10[it] * (a[i] % p10[x + 1] / p10[x]);
        if (j > x)
          it += 2;
        else
          it++;
      }
      ans += (cnt[j] * sum);
      sum = 0;
      it = -1;
      for (int x = 0; x < zn[i]; x++) {
        if (j > x)
          it += 2;
        else
          it++;
        sum += (p10[it] * (a[i] % p10[x + 1] / p10[x]));
      }
      ans += (cnt[j] * sum);
      cnt[zn[i]]++;
    }
  }
  for (int i = 0; i < n; i++)
    for (int x = 0; x < zn[i]; x++)
      ans += (p10[2 * x] + p10[2 * x + 1]) * (a[i] % p10[x + 1] / p10[x]);
  cout << (long long) (ans % MOD);
  return 0;
}