#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  n /= 2;

  auto ask = [&](int i)
  {
    cout << "? " << i % (n * 2) + 1 << endl;
    int resp;
    cin >> resp;
    return resp;
  };

  int d0 = ask(0) - ask(n), ans = -1;
  if (!d0) ans = 1;
  else
  {
    int low = d0 > 0 ? 0 : n;
    int high = d0 > 0 ? n : n * 2;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      int d = ask(mid + n) - ask(mid);
      if (!d)
      {
        ans = mid + 1;
        break;
      }
      if (d < 0) low = mid + 1;
      else high = mid - 1;
    }
  }

  cout << "! " << ans << endl;
  cout.flush();
}