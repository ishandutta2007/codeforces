#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;

    auto ask = [&](int l, int r)
    {
      cout << "? " << l << ' ' << r << endl;
      cout.flush();
      long long resp;
      cin >> resp;
      return resp;
    };


    long long total = ask(1, n);
    int low = 2, high = n, i = 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (ask(mid, n) == total)
      {
        i = mid;
        low = mid + 1;
      }
      else high = mid - 1;
    }

    long long x = ask(i + 1, n);
    int j = i + total - x + 1;
    long long leftInv = (j - i) * (j - i - 1LL) / 2;
    long long rightInv = total - leftInv;
    int k = j + int(sqrt(rightInv * 2));
    cout << "! " << i << ' ' << j << ' ' << k << endl;
    cout.flush();
  }
}