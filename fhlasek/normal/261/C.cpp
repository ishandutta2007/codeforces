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

#define MAX 45
long long c[MAX][MAX];

int main(int argc, char *argv[]){
  REP(i, MAX) REP(j, MAX){
    if(j == 0 || i == j) c[i][j] = 1;
    else if(i > j) c[i][j] = c[i-1][j] + c[i-1][j-1];
  }
  long long N, t, ans = 0;
  cin >> N >> t;
  N++;
  long long T; 
  for(T = 0; T < MAX; T++) if(1LL << T == t) break;
  if(T == MAX){ cout << 0 << endl; return 0; }
  T++;
  ans = c[MAX-1][T];
  int tmp = 0;
  FORD(i, MAX-2, 0){
    if(N & (1LL << i)) tmp++; 
    else if (T - tmp - 1 >= 0) ans -= c[i][T - tmp - 1];
  }
  if(T == 1) ans--;
  cout << ans << endl;
  return 0;
}