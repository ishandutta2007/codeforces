#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool cmp(int a, int b)
{
  return (a & 1) < (b&1);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), cmp); // put the even ones before the odd ones
    int ans = 0;
    for (int i = 0; i < n;i++) for (int j = i + 1; j < n; j++)
      ans += (__gcd(a[i], 2 * a[j]) > 1);
    cout << ans << "\n";
  }
  return 0;
}