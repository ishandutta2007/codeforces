#include <bits/stdc++.h>
using namespace std;

int n, k;

pair<int, int> ask(vector<int> a)
{
  cout << '?';
  for (int x : a)
    cout << ' ' << x + 1;
  cout << '\n';
  cout.flush();
  pair<int, int> resp;
  cin >> resp.first >> resp.second;
  resp.first--;
  return resp;
}

void answer(int x)
{
  cout << "! " << x << '\n';
  cout.flush();
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  if (k == 1)
    answer(1);

  vector<int> a(k);
  for (int i = 0; i < k; i++)
    a[i] = i;
  auto resp0 = ask(a);
  swap(a[0], a[resp0.first]);
  int y = a[1];

  a[1] = k;
  auto resp1 = ask(a);
  a[1] = y;

  int cntEqual = 0, cntDiff = 0, isGreater = -1;
  for (int i = 2; i < k; i++)
  {
    int tmp = a[i];
    a[i] = k;
    auto u = ask(a);
    if (u.first == resp1.first) cntEqual++;
    else
    {
      cntDiff++;
      if (isGreater >= 0) assert((u.second < resp1.second) == isGreater);
      else isGreater = u.second < resp1.second;
    }
    a[i] = tmp;
  }

  if (!cntDiff)
  {
    vector<int> b;
    for (int i = 0; i <= k; i++)
      if (i != resp0.first)
        b.push_back(i);
    auto resp2 = ask(b);
    if (resp0.first == resp1.first) answer(resp0.second < resp2.second ? 1 : k);
    else answer(resp0.second < resp1.second ? k : 1);
  }
  else if (isGreater) answer(k - cntDiff);
  else answer(cntDiff + 1);
}