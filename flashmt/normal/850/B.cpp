#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;
const int A = 1000000;

int cnt[A * 2 + 10];
long long sum[A * 2 + 10];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, x, y, v;
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++)
  {
    cin >> v;
    cnt[v]++;
    sum[v] += v;
  }

  for (int i = 1; i <= A * 2; i++)
  {
    cnt[i] += cnt[i - 1];
    sum[i] += sum[i - 1];
  }

  long long ans = 1LL * n * x;
  for (int g = 2; g <= A; g++)
  {
    long long cost = 0;
    int v = 0;
    while (v <= A && cost < ans)
    {
      v += g;
      int low = max(v - x / y - 1, v - g);
      long long numAdd = 1LL * (cnt[v - 1] - cnt[low]) * v - (sum[v - 1] - sum[low]);
      if (ans / y < numAdd)
      {
        cost = ans;
        break;
      }
      cost += numAdd * y;
      cost += 1LL * (cnt[low] - cnt[v - g]) * x;
    }
    ans = min(ans, cost);
  }

  cout << ans << endl;
}