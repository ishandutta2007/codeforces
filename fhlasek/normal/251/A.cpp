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

#define MAXN 111111

int a[MAXN];

int main(int argc, char *argv[]){
  int N, D;
  scanf("%d%d", &N, &D);
  REP(i, N) scanf("%d", a + i);
  long long ans = 0;
  int left = 0;
  REP(i, N){
    while(left < N && a[left] - a[i] <= D) left++;
    if(left - i > 2) ans += (long long)(left - i - 1) * (left - i - 2) / 2;
  }
  cout << ans << endl;
   
  return 0;
}