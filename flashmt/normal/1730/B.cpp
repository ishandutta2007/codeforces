#include <bits/stdc++.h>
using namespace std;
const double oo = 1e19;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;
    vector<int> t(n);
    for (int &x : t)
      cin >> x;

    double low = *max_element(begin(t), end(t)), high = 2e8, ans;
    for (int _ = 0; _ < 60; _++)
    {
      double mid = (low + high) / 2;
      double maxL = -oo, minR = oo;
      for (int i = 0; i < n; i++)
      {
        maxL = max(maxL, a[i] - (mid - t[i]));
        minR = min(minR, a[i] + (mid - t[i]));
      }
      if (maxL <= minR)
      {
        ans = maxL;
        high = mid;
      }
      else low = mid;
    }

    cout << fixed << setprecision(9) << ans << endl;
  }
}