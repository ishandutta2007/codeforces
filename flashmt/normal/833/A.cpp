#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test, x;
  scanf("%d", &test);
  while (test--)
  {
    int x, y;
    scanf("%d%d",&x, &y);
    
    long long xy = 1LL * x * y;
    long long low = 1, high = 1000000, res;
    while (low <= high)
    {
      long long mid = (low + high) / 2;
      if (mid * mid * mid <= xy)
      {
        res = mid;
        low = mid + 1;
      }
      else high = mid - 1;
    }

    string ans = "Yes";
    if (res * res * res != xy) ans = "No";
    else if (x % res || y % res) ans = "No";
    else if ((x / res) * (y / res) != res) ans = "No";

    puts(ans.c_str());
  }
}