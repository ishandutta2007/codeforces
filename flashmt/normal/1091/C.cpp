#include <bits/stdc++.h>
using namespace std;

long long calc(int n, int k)
{
  int num = n / k;
  return (1LL + (num - 1) * k + 1) * num / 2;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<long long> ans;
  for (int i = 1; i * i <= n; i++)
    if (n % i == 0)
    {
      ans.insert(calc(n, i));
      ans.insert(calc(n, n / i));
    }

  for (auto x : ans)
    cout << x << ' ';
}