/* Written by Filip Hlasek 2013 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 1111111
long long X, Y;
char x[MAXN], y[MAXN];

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

long long total;

long long N, M;

long long cntx[30], cnty[30];
long long G;

void calculate(long long d) {
  REP(i, 30) cntx[i] = cnty[i] = 0;
  for (long long i = d; i < X; i += G) cntx[x[i] - 'a']++;
  for (long long i = d; i < Y; i += G) cnty[y[i] - 'a']++;
  long long totalx = 0, totaly = 0;
  REP(i, 30) { totalx += cntx[i]; totaly += cnty[i]; }
  REP(i, 30) total += ((long long)cntx[i] * (totaly - cnty[i]) + (long long)cnty[i] * (totalx - cntx[i]));
}

int main(int argc, char *argv[]) {
  cin >> N >> M;
  scanf("%s", x);
  scanf("%s", y);

  X = strlen(x);
  Y = strlen(y);

  G = gcd(X, Y);
  REP(i, G) calculate(i);

  cout << total * (N * G / Y) / 2 << endl;
   
  return 0;
}