#include <bits/stdc++.h>
using namespace std;
const int X[] = {0, 1, 0, 1, 2};
const int Y[] = {1, 0, 2, 1, 0};

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    string a[200];
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    vector<int> goals = {0, 0, 1, 1, 1};
    int diff = 0;
    for (int i = 0; i < 5; i++)
      if (a[X[i]][Y[i]] - '0' != goals[i])
        diff++;

    if (diff > 2)
    {
      diff = 5 - diff;
      for (int &x : goals)
        x ^= 1;
    }

    cout << diff << endl;
    for (int i = 0; i < 5; i++)
      if (a[X[i]][Y[i]] - '0' != goals[i])
        cout << X[i] + 1 << ' ' << Y[i] + 1 << endl;
  }
}