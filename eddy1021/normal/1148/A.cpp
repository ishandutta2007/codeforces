#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
  LL a, b, ab, g;
  cin >> a >> b >> ab;
  g = min(a, b);
  cout << ab * 2 + g * 2 + (a + b - g - g > 0) << endl;
}