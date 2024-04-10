#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, cnt[101] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      cnt[x]++;
    }

    for (int i = 0; i <= 100; i++)
      if (cnt[i])
      {
        cout << i << ' ';
        cnt[i]--;
      }

    for (int i = 0; i <= 100; i++)
      while (cnt[i]--)
        cout << i << ' ';
    cout << endl;
  }
}