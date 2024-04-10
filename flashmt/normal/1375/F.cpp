#include <bits/stdc++.h>
using namespace std;

int ask(long long k)
{
  cout << k << endl;
  cout.flush();
  int res;
  cin >> res;
  return res - 1;
}

int main()
{
  long long a[3];
  for (int i = 0; i < 3; i++)
    cin >> a[i];
  cout << "First" << endl;
  cout.flush();
  int last = -1;
  while (1)
  {
    int x = 0, z = 0;
    for (int i = 1; i < 3; i++)
      if (a[i] < a[x]) x = i;
      else if (a[i] > a[z]) z = i;
    int y = 3 - x - z;

    if (last == z && a[y] * 2 == a[x] + a[z])
    {
      assert(ask(a[y] - a[x]) < 0);
      return 0;
    }

    long long v = a[z] * 2 - a[x] - a[y];
    last = ask(v);
    a[last] += v;
  }
}