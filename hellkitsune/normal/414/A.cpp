#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

const int maxp = 2e6;
bool primes[maxp] = {};
int n;
int k;

void init() {
  for (int i = 2; i * i < maxp; ++i)
    if (!primes[i])
      for (int j = i * i; j < maxp; j += i)
        primes[j] = true;
}

int main() {
  scanf("%d%d", &n, &k);
  if (n == 1) {
    if (k == 0)
      cout << "1" << endl;
    else
      cout << "-1" << endl;
    return 0;
  }
  if (n / 2 > k) {
    cout << "-1" << endl;
    return 0;
  }

  init();

  if (k > n / 2) {
    n -= 2;
    k -= n / 2;
    printf("%d %d ", k, 2 * k);
  }

  int l = 2;
  while (primes[l] || (l == k))
      ++l;
  while (n > 1) {
    printf("%d ", l);
    ++l;
    while (primes[l] || (l == k))
      ++l;
    printf("%d ", l);
    ++l;
    while (primes[l] || (l == k))
      ++l;
    n -= 2;
  }

  if (n)
    printf("%d", n);

  printf("\n");
  return 0;
}