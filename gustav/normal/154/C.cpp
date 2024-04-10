#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 1000005;

const int base1 = 57, mod1 = 1e9 + 7;
const int base2 = 87, mod2 = 1e9 + 9;
int pw1[MAXN];
int pw2[MAXN];

int add(int a, int b, int mod) { return (a + b) % mod; }
int mul(int a, int b, int mod) { return (llint)a * b % mod; }

int n, m;
vector< int > G[MAXN];
llint val[MAXN];
llint xval[MAXN];

int main(void) 
{
  pw1[0] = pw2[0] = 1;
  FOR(i, 1, MAXN) {
    pw1[i] = mul(pw1[i - 1], base1, mod1);
    pw2[i] = mul(pw2[i - 1], base2, mod2);
  }

  scanf("%d%d", &n, &m);

  int n_ones1 = 0; REP(i, n) n_ones1 = add(mul(n_ones1, base1, mod1), 1, mod1);
  int n_ones2 = 0; REP(i, n) n_ones2 = add(mul(n_ones2, base2, mod2), 1, mod2);

  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector< llint > v;
  llint sol = 0;

  REP(i, n) {
    int h1 = n_ones1;
    int h2 = n_ones2;

    for (int j : G[i]) {
      h1 = add(h1, pw1[j], mod1);
      h2 = add(h2, pw2[j], mod2);
    }

    val[i] = ((llint)h1 << 32) | h2;
    xval[i] = ((llint)add(h1, pw1[i], mod1) << 32) | add(h2, pw2[i], mod2);
  }

  REP(i, n) {
    v.push_back(val[i]);
    for (auto j : G[i]) 
      if (i < j && xval[i] == xval[j])
	++sol;
  }

  sort(v.begin(), v.end());

  for (int i = 0, j; i < n; i = j) {
    for (j = i + 1; j < n && v[i] == v[j]; ++j);
    llint k = j - i;
    sol += k * (k - 1) / 2;
  }

  printf("%lld\n", sol);

  return 0;
}