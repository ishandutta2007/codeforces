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

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define log(...) fprintf(stderr, ##__VA_ARGS__)

const int mod = 1000000007;

int main(void)
{
  llint a, b;
  cin >> a >> b;

  llint A = (a * (a + 1) / 2) % mod;
  llint B = (b * (b - 1) / 2) % mod;
  llint C = (b * A + a) % mod;

  cout << B * C % mod << endl;

  return 0;
}