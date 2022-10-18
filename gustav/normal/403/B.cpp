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
#define MAX 5005

unordered_map< int, int > memo;
unordered_set< int > bad;

bool is_bad(int n) {
  return bad.find(n) != bad.end();
}

int f(int n) {
  if (n == 1) return 0;
  if (memo.count(n)) return memo[n];
  if (is_bad(n)) return memo[n] = -1;

  for (int i = 2; i * i <= n; ++i) 
    if (n % i == 0) 
      return memo[n] = f(n / i) + (is_bad(i) ? -1 : +1);

  return memo[n] = +1;
}

int N, M;
int a[MAX], b;
int g[MAX];
int dp[2][MAX];

int main(void)
{
  scanf("%d%d", &N, &M);

  for (int i = 0; i < N; ++i)
    scanf("%d", a + i);

  for (int i = 0; i < M; ++i) {
    scanf("%d", &b);
    bad.insert(b);
  }

  a[N] = 1;
  g[0] = a[0];
  for (int i = 1; i <= N; ++i)
    g[i] = __gcd(a[i], g[i - 1]);

  for (int last = 1; last <= N; ++last)
    dp[0][last] = max(0, f(a[0] / g[last]));

  for (int r = 1; r < N; ++r) {
    int R = r % 2;
    for (int last = r + 1; last <= N; ++last) {
      dp[R][last] = max(f(a[r] / g[r]) + dp[R ^ 1][r],
                        f(a[r] / g[last]) + dp[R ^ 1][last]);
    }
  }

  printf("%d\n", dp[(N - 1) % 2][N]);
    
  return 0;
}