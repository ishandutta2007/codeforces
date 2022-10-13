#include <bits/stdc++.h>
using namespace std;

int n, b[333];
int a[333][1000], len[333];

void att(int id);

void att2(int id, int digit, int curId, int cmp, int sum)
{
  if (curId == digit)
  {
    if (sum > 9) return;
    if (!cmp && sum <= a[id - 1][curId]) return;
    a[id][curId] = sum;
    att(id + 1);
    return;
  }
  
  for (int x = (curId > 1 ? 0 : 1); x < 10; x++)
    if (x <= sum && (digit - curId) * 9 >= sum - x && (cmp || x >= a[id - 1][curId]))
    {
      a[id][curId] = x;
      att2(id, digit, curId + 1, cmp | (x > a[id - 1][curId]), sum - x);
    }
}

void att(int id)
{
  if (id > n)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= len[i]; j++) cout << a[i][j];
      cout << endl;
    }
    exit(0);
  }
  
  for (int digit = (b[id] + 8) / 9;; digit++)
  {
    if (digit < len[id - 1]) continue;
    int cmp = (digit > len[id - 1]);
    len[id] = digit;
    att2(id, digit, 1, cmp, b[id]);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> b[i];
  len[0] = 1;
  att(1);
}