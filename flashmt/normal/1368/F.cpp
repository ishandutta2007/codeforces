#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  int ans = 0, block = 1;
  for (int i = 2; i * i <= n; i++)
  {
    int x = n / i * (i - 1) + max(0, n % i - 1) - i + 1;
    if (x > ans)
    {
      ans = x;
      block = i;
    }
  }

  vector<int> a;
  for (int i = 0; i < n; i += block)
    for (int j = 0; j < block - 1 && i + j < n - 1; j++)
      a.push_back(i + j);

  vector<int> isOn(n);
  while (1)
  {
    vector<int> off;
    for (int i : a)
      if (!isOn[i])
      {
        off.push_back(i);
        if (size(off) == block)
          break;
      }

    if (size(off) < block)
    {
      cout << 0 << endl;
      cout.flush();
      return 0;
    }

    cout << block;
    for (int i : off)
    {
      cout << ' ' << i + 1;
      isOn[i] = 1;
    }
    cout << endl;
    cout.flush();

    int x;
    cin >> x;
    if (x < 0)
      return 0;

    x--;
    for (int i = 0; i < block; i++)
      isOn[(x + i) % n] = 0;
  }
}