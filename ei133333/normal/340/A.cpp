#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int INF = 1 << 30;
int main()
{
  int64 x, y, a, b;
  cin >> x >> y >> a >> b;
  int64 xy = x / __gcd(x, y) * y;
  cout << b / xy - (a - 1) / xy << endl;
}