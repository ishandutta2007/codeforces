#include <cstdio>

#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n, k;
  scanf("%d", &n);
  vector<ll> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &a[i]);
  sort(a.begin(), a.end());
  scanf("%d", &k);
  vector<ll> ans(k);
  vector<pair<ll, int>> v;
  v.reserve(n + k - 1);
  for (int i = 1; i < n; ++i)
    v.emplace_back(a[i] - a[i - 1], -1);
  for (int rep = 0; rep < k; ++rep) {
    ll l, r;
    scanf("%lld%lld", &l, &r);
    v.emplace_back(r - l + 1, rep);
  }
  ll sum = 0;
  sort(v.begin(), v.end());
  for (const auto& pr : v)
    if (pr.second == -1) {
      sum += pr.first;
      --n;
    } else
      ans[pr.second] = sum + n * (ll)pr.first;
  for (int i = 0; i < k; ++i)
    printf("%lld ", ans[i]);
  return 0;
}