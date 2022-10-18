/* Writen by Filip Hlasek 2012 */
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
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define MOD 1000000007
long long ans[2][2] = {{1,0},{0,1}}, tmp[2][2];

int main(int argc, char *argv[]){
  long long exponent;
  cin >> exponent;
  long long base[2][2] = {{3,1},{1,3}}, m[2][2] = {{3,1},{1,3}};
  while(exponent){
    if(exponent & 1){
      REP(i,2) REP(j,2){ tmp[i][j] = 0; REP(k,2) tmp[i][j] += ans[i][k] * m[k][j]; }
      REP(i,2) REP(j,2) ans[i][j] = tmp[i][j] % MOD;
    }
    REP(i,2) REP(j,2){ tmp[i][j] = 0; REP(k,2) tmp[i][j] += m[i][k] * m[k][j]; }
    REP(i,2) REP(j,2) m[i][j] = tmp[i][j] % MOD;
    exponent /= 2;
  }
  cout << ans[0][0] << endl;
  return 0;
}