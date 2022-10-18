#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back
#define MAX 1000000000

vector< llint > sol;

llint sumdig(llint n) {
  if (n == 0) return 0;
  return sumdig(n / 10) + n % 10;
}

llint pwr(llint a, llint b) {
  if (b == 0) return 1;
  llint r = pwr(a * a, b / 2);
  if (b % 2 == 1) return r * a;
  return r;
}

int main(void)
{
  llint a, b, c;
  cin >> a >> b >> c;

  for (llint ry = 0; ry <= 100; ++ry) {
    llint y = pwr(ry, a);
    llint x = b * y + c;
    if (b * pwr(sumdig(x), a) + c == x && x < MAX && x > 0)
      sol.pb(x);
  }

  cout << sol.size() << endl;
  for (auto s : sol) cout << s << " ";
  cout << endl;

  return 0;
}