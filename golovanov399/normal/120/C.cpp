#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  int n, k;
  cin >> n >> k;
  
  int res = 0;
  
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    
    if (x >= 3 * k) {
      res += x - 3 * k;
    }
    else {
      res += x % k;
    }
  }
  
  cout << res << "\n";

  
  return 0;
}