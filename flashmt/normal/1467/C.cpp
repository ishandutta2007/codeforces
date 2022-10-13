#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n[3], minVal[3] = {oo, oo, oo};
  for (int i = 0; i < 3; i++)
    cin >> n[i];

  long long sum[3] = {0};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n[i]; j++)
    {
      int x;
      cin >> x;
      minVal[i] = min(minVal[i], x);
      sum[i] += x;
    }

  long long best = min({sum[0], sum[1], sum[2]});
  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 3; j++)
      best = min(best, 1LL * minVal[i] + minVal[j]);

  cout << sum[0] + sum[1] + sum[2] - best * 2 << endl;
}