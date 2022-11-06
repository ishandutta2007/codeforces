#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

lint gcd(lint a, lint b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main() {
  lint x, y;
  cin >> x >> y;

  lint g = gcd(x, y);
  if (g != 1) {
    printf("Impossible\n");
    return 0;
  }

  {
    vector<lint> res;
    lint a = x, b = y;
    while (a > 0 && b > 0) {
      if (a >= b) {
	lint many = a/b;
	res.push_back(many);
	a -= many * b;
      } else {
	lint many = b/a;
	res.push_back(-many);
	b -= many * a;
      }

      if (res.size() >= 2) {
	lint f = res.front();
	if (f > 0) printf("%lldA", f);
	else if (f < 0) printf("%lldB", -f);
	res.erase(res.begin());
      }
    }

    lint x = res.back();
    res.pop_back();
    if (x > 0) --x;
    if (x < 0) ++x;
    if (x) res.push_back(x);

    for (int i = 0; i < (int)res.size(); ++i) {
      if (res[i] > 0) printf("%lldA", res[i]);
      else printf("%lldB", -res[i]);
    }
    printf("\n");
  }

  return 0;
}