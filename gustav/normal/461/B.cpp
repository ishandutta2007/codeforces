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

const int mod = 1000000007;

#define MAXN 100005

int mul(int a, int b) { return (llint)a * b % mod; }
int add(int a, int b) { return (a + b) % mod; }

int N;
int p;
bool is_black[MAXN];

int sib[MAXN];
int child[MAXN];

int dp[MAXN][2];
int dpc[MAXN][2];

int f(int n, bool take_black);
int g(int c, bool take_black);

int f(int n, bool take_black) {
  int &ret = dp[n][take_black];
  if (ret >= 0) return ret;

  if (is_black[n]) {
    if (take_black == false) 
      return ret = 0;
    return ret = g(child[n], 0);
  }
  
  return ret = g(child[n], take_black);
} 

int g(int c, bool take_black) {
  if (c == -1) return take_black == 0;

  int &ret = dpc[c][take_black];
  if (ret >= 0) return ret;

  ret = 0;

  if (take_black) {
    ret = add(ret, mul(f(c, 1), g(sib[c], 0)));
    ret = add(ret, mul(add(f(c, 0), f(c, 1)), g(sib[c], 1)));
  } else {
    ret = add(ret, mul(add(f(c, 0), f(c, 1)), g(sib[c], 0)));
  }

  return ret;
}

int main(void)
{
  memset(child, -1, sizeof child);
  memset(dp, -1, sizeof dp);
  memset(dpc, -1, sizeof dpc);

  cin >> N;
  REP(i, N - 1) {
    cin >> p;
    sib[i + 1] = child[p];
    child[p] = i + 1;
  }

  REP(i, N) cin >> is_black[i];

  cout << f(0, 1) << endl;

  return 0;
}