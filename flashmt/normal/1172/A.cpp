#include <bits/stdc++.h>
using namespace std;

int n, hand[200200], pile[200200], at[200200];

void check()
{
  if (!at[1])
    return;

  for (int i = at[1] + 1; i <= n; i++)
    if (pile[i] != pile[i - 1] + 1)
      return;

  int turn = 0;
  for (int i = pile[n] + 1; i <= n; i++)
  {
    if (!hand[i] && at[i] > turn)
      return;
    turn++;
  }

  cout << turn << endl;
  exit(0);
}

int main()
{
  int x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &x);
    hand[x] = 1;
  }
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", pile + i);
    at[pile[i]] = i;
  }

  check();

  int turn = 0;
  for (int i = 1; i <= n; i++)
  {
    if (!hand[i] && at[i] > turn) turn += at[i] - turn + 1;
    else turn++;
  }
  cout << turn << endl;
}