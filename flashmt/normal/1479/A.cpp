#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int a[100100], n;

int ask(int x)
{
  if (!x || x > n)
    return oo;
  if (a[x])
    return a[x];
  cout << "? " << x << endl;
  cout.flush();
  int v;
  cin >> v;
  return a[x] = v;
}

void answer(int x)
{
  cout << "! " << x << endl;
  cout.flush();
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  if (n == 1)
    answer(1);
  if (ask(1) < ask(2))
    answer(1);
  if (ask(n) < ask(n - 1))
    answer(n);

  int low = 2, high = n - 1;
  while (low + 6 <= high)
  {
    int m1 = (low * 2 + high) / 3;
    int m2 = (low + high * 2) / 3;
    if (ask(m1) < ask(m2)) high = m2;
    else low = m1;
  }

  for (int i = low; i <= high; i++)
    if (ask(i) < min(ask(i - 1), ask(i + 1)))
      answer(i);
}