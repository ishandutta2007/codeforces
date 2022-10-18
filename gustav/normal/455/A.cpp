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
#define MAX 100005

int N, a;
llint dp[MAX];
int cnt[MAX];

int main(void)
{
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) {
    scanf("%d", &a);
    ++cnt[a];
  }

  dp[MAX - 1] = 0;
  dp[MAX - 2] = 0;
  for (int i = MAX - 3; i >= 0; --i) {
    dp[i] = dp[i + 1];
    dp[i] = max((llint)cnt[i] * i + dp[i + 2], dp[i]);
  }

  cout << dp[0] << endl;

  
  return 0;
}