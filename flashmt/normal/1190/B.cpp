#include <bits/stdc++.h>
using namespace std;

void lose()
{
  cout << "cslnb" << endl;
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  map <int, int> cnt;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    cnt[x]++;
  }

  if (cnt.count(0))
  {
    if (cnt[0] == n || cnt[0] == 2)
      lose();
  }

  int num2 = 0, id = 0, ans = 0;
  for (auto u : cnt)
    if (u.second > 2) lose();
    else if (u.second == 2)
    {
      if (cnt.count(u.first - 1)) lose();
      else
      {
        num2++;
        ans ^= (u.first - 1 - id) % 2;
        id++;
        ans ^= (u.first - id) % 2;
        id++;
      }
    }
    else
    {
      ans ^= (u.first - id) % 2;
      id++;
    }

  if (num2 > 1)
    lose();

  if (num2)
    ans ^= 1;

  cout << (ans ? "sjfnb" : "cslnb") << endl;
}