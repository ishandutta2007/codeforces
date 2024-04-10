#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 100005;

#define OFF puts("Already off")
#define ON puts("Already on")
#define OK puts("Success")

int n, m;
int p[MAXN];
int on[MAXN];
int who[MAXN];

vector< int > unique_factors(int n) {
  vector< int > ret;
  while (n != 1) {
    int c = p[n];
    ret.push_back(c);
    while (n % c == 0) n /= c;
  }
  return ret;
}

int main(void) 
{
  p[1] = 1;
  FOR(i, 1, MAXN) {
    if (p[i] != 1) continue;
    for (int j = i; j < MAXN; j += i)
      p[j] = i;
  }

  scanf("%d%d", &n, &m);

  REP(i, m) {
    char op; int x;
    scanf(" %c%d", &op, &x);

    if (op == '-') {
      if (!on[x]) {
	OFF;
      } else {
	OK;
	auto v = unique_factors(x);
	for (int j : v) who[j] = 0;
	on[x] = 0;
      }
    } else {
      if (on[x]) {
	ON;
      } else {
	int conflict = 0;
	auto v = unique_factors(x);
	for (int j : v) if (who[j]) conflict = who[j];

	if (conflict) {
	  printf("Conflict with %d\n", conflict);
	} else {
	  OK;
	  for (int j : v) who[j] = x;
	  on[x] = 1;
	}
      }
    }
  }

  return 0;
}