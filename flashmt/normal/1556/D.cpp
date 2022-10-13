#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;

  auto ask = [&](int x, int y)
  {
    cout << "or " << x + 1 << ' ' << y + 1 << endl;
    cout.flush();
    long long orRes;
    cin >> orRes;
    cout << "and " << x + 1 << ' ' << y + 1 << endl;
    cout.flush();
    long long andRes;
    cin >> andRes;
    return orRes + andRes;
  };

  vector<long long> s(n);
  for (int i = 1; i < n; i++)
    s[i] = ask(0, i);
  s[0] = ask(1, 2);
  vector<long long> a(n);
  a[0] = (s[0] + s[1] + s[2]) / 2 - s[0];
  for (int i = 1; i < n; i++)
    a[i] = s[i] - a[0];

  sort(begin(a), end(a));
  cout << "finish " << a[k - 1] << endl;
  cout.flush();
}