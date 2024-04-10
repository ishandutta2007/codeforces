#include <bits/stdc++.h>
using namespace std;

int n;
vector < pair<int, long long> > a;

int numBit(long long x)
{
  return x == 1 ? 1 : numBit(x / 2) + 1;
}

int main()
{
  ios::sync_with_stdio(0);
  long long x;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    a.push_back({numBit(x), x});
  }
  sort(a.begin(), a.end(), greater < pair<int, long long> >());
  vector <long long> ans, tmp;
  for (int i = 0; i < n;)
  {
    int ii = i, curBit = a[i].first;
    while (ii < n && a[ii].first == curBit)
      ii++;

    tmp.clear();
    tmp.push_back(a[i++].second);
    for (auto x : ans)
    {
      tmp.push_back(x);
      if ((x >> (curBit - 1) & 1) && i < ii)
        tmp.push_back(a[i++].second);
    }
    if (i < ii)
    {
      cout << "No" << endl;
      return 0;
    }
    ans = tmp;
  }
  cout << "Yes" << endl;
  for (auto x : ans)
    cout << x << ' ';
}