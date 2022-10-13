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
    int n;
    cin >> n;

    auto query = [&](int lFrom, int lTo, int r)
    {
      cout << "? " << lTo - lFrom + 1 << ' ' << 1 << endl;
      for (int i = lFrom; i <= lTo; i++)
        cout << i + 1 << ' ';
      cout << endl;
      cout << r + 1 << endl;
      cout.flush();
      int resp;
      cin >> resp;
      return resp;
    };

    vector<int> isMagnet(n);
    int x = -1;
    for (int i = 1; i < n; i++)
      if (query(0, i - 1, i))
      {
        x = i;
        isMagnet[i] = 1;
        break;
      }
    assert(x >= 0);

    int low = 0, high = x - 1, y = -1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (query(0, mid, x))
      {
        y = mid;
        high = mid - 1;
      }
      else low = mid + 1;
    }
    assert(y >= 0);
    isMagnet[y] = 1;

    for (int i = x + 1; i < n; i++)
      if (query(x, x, i))
        isMagnet[i] = 1;

    cout << "! " << count(begin(isMagnet), end(isMagnet), 0);
    for (int i = 0; i < n; i++)
      if (!isMagnet[i])
        cout << ' ' << i + 1;
    cout << endl;
    cout.flush();
  }
}