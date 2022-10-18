#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 100005;

int n;
vector< int > G[MAXN];
vector< int > stk;
int cnt[MAXN];

void euler(int i) {
  while (!G[i].empty()) {
    int cur = G[i].back(); G[i].pop_back();
    euler(cur);
    if (cur == (2 * i) % n)
      stk.push_back(2 * i);
    else
      stk.push_back(2 * i + 1);
  }
}

int main(void) 
{
  scanf("%d", &n);
  
  if (n % 2 == 1) {
    puts("-1");
    exit(0);
  }

  if (n == 2) {
    puts("0 1 0");
    exit(0);
  }

  n /= 2;
  REP(i, n) {
    G[i].push_back((2 * i + 1) % n);
    G[i].push_back((2 * i) % n);
  }

  euler(0);
  reverse(stk.begin(), stk.end());

  n *= 2;
  for (int i : stk) printf("%d ", i);

  printf("0\n");

  return 0;
}