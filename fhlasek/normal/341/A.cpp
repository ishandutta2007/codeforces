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

#define MAXN 111111
int N, a[MAXN];

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
  sort(a, a + N);
  long long num = 0, den = N;
  long long sum = 0;
  REP(i, N) sum += a[i];
  num += sum;

  REP(i, N - 1) num += (long long)(a[i+1] - a[i]) * (i + 1) * (N - i - 1) * 2;
  /*
  REP(i, N) {
    sum -= a[i];
    num += 2 * (sum - (N - 1 - i) * a[i]);
  }
  */
  long long g = gcd(num, den);
  cout << num / g << " " << den / g << endl;
  return 0;
}