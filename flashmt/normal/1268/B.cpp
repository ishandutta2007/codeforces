#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long cnt[2] = {0};
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    cnt[i % 2] += x / 2;
    cnt[1 - i % 2] += x / 2 + x % 2;
  }

  cout << min(cnt[0], cnt[1]) << endl;
}