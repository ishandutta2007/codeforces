/* Written by Filip Hlasek 2012 */
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

#define INF (1000000000000000000LL)

#define MAXN 1111111
long long d[MAXN];
long long A, B;
int K;

long long solve(long long A, long long B){
  REP(i, A + 1) d[i] = INF;
  d[A] = 0;
  FORD(i, A, B+1){
    d[i-1] = min(d[i-1], d[i] + 1);
    FOR(j, 2, K) if(i % j) d[i-i%j] = min(d[i-i%j], d[i] + 1);
  }
  return d[B];
}

const int C = 360360;

int main(int argc, char *argv[]){
  cin >> A >> B >> K;
  if(A / C == B / C) cout << solve(A % C, B % C) << endl; 
  else cout << solve(A % C, 0) + solve(C, B % C) + (A / C - B / C - 1) * solve(C, 0) << endl;
  return 0;
}