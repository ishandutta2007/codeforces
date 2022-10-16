// Example program
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t --> 0){
      long long a,b,c;
      cin >> a >> b >> c;
      cout << (2*max({a,b,c}) - 1 <= a+b+c?"Yes":"No") << "\n";
  }
}