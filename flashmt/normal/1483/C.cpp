#include <bits/stdc++.h>
using namespace std;
const int N = 300300;
const long long oo = 1LL << 60;

int n, h[N], b[N], st[N], num;
long long f[N], maxSuffix[N];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> h[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];

  set<pair<long long, int>> s; // b[i] + maxSuffix[i]
  num = 1;
  st[0] = f[0] = maxSuffix[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    maxSuffix[i] = -oo;
    while (num && h[i] <= h[st[num]])
    {
      int j = st[num--];
      maxSuffix[i] = max(maxSuffix[i], max(f[j], maxSuffix[j]));
      s.erase({maxSuffix[j] + b[j], j});
    }
    maxSuffix[i] = max(maxSuffix[i], f[st[num]]);
    s.insert({maxSuffix[i] + b[i], i});
    f[i] = s.rbegin()->first;
    st[++num] = i;
  }

  cout << f[n] << endl;
}