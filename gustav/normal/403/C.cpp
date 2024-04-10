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
#define MAX 2005

int N;
int bio[MAX], cookie;
int a[MAX][MAX];

int last = -1;

int dfs1(int n) {
  if (bio[n] == cookie) return 0;
  bio[n] = cookie;
  
  int ret = 1;

  for (int i = 0; i < N; ++i) 
    if (a[n][i]) ret += dfs1(i);

  return ret;
}

int dfs2(int n) {
  if (bio[n] == cookie) return 0;
  bio[n] = cookie;
  
  int ret = 1;

  for (int i = 0; i < N; ++i) 
    if (a[i][n]) ret += dfs2(i);

  return ret;
}

int main(void)
{
  scanf("%d", &N);

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      scanf("%d", &a[i][j]);

  ++cookie;
  if (dfs1(0) != N) {
    puts("NO");
    return 0;
  }
  
  ++cookie;
  if (dfs2(0) != N) {
    puts("NO");
    return 0;
  }

  puts("YES");

  return 0;
}