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
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;


int main(int argc, char *argv[]){
  long long ans = 0;
  int N, M;
  scanf("%d%d", &N, &M);
  REP(i, N){
    int t1, t2, t, x, cost;
    scanf("%d%d%d%d", &t1, &t2, &x, &cost);
    t = max(0, t2 - t1);
    long long best = cost + (long long)x * M;
    if(t){
      if(t >= M) best = cost;
      else{
        int buses = M / t;
        best = min(best, (long long)cost * (buses + 1));
        if(M % t) best = min(best, (long long)cost * buses + (long long) x * (M - t * (buses - 1)));
        else best = min(best, (long long)cost * buses);
      }
    }
    ans += best;
  }
  cout << ans << endl;
  return 0;
}