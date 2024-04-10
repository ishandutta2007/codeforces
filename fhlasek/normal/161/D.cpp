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

#define MAXN 111111
#define MAXK 555

int N,K,eA[MAXN],eB[MAXN],start[MAXN],tmp[MAXN],n[2*MAXN],father[MAXN];
queue<int> q;
int t[MAXN],T=0;

long long dp[MAXN][MAXK];

int main(int argc, char *argv[]){
	scanf("%d%d",&N,&K);
	REP(i,N-1){
		scanf("%d%d",eA+i,eB+i);
		eA[i]--;
		eB[i]--;
		tmp[eA[i]]++;
		tmp[eB[i]]++;
	}
	REP(i,N) start[i+1] = start[i] + tmp[i];
	REP(i,(N-1)) n[start[eA[i]] + (--tmp[eA[i]])] = eB[i];
	REP(i,(N-1)) n[start[eB[i]] + (--tmp[eB[i]])] = eA[i];
	father[0] = -1;
	q.push(0);
	while(!q.empty()){
		int x = q.front();
		q.pop();
    t[T++] = x;
		for(int i = start[x]; i < start[x+1]; i++) if(n[i] != father[x]){
			q.push(n[i]);
			father[n[i]] = x;
		}
	}
  reverse(t,t+T);
  long long ans = 0;
	REP(j,T){
    int m = t[j];
    dp[m][0] = 1;
		for(int i = start[m]; i < start[m+1]; i++) if(father[m] != n[i]){
      FOR(k,0,K-1) ans += dp[m][k] * dp[n[i]][K-k-1];
      FOR(k,0,K-1) dp[m][k+1] += dp[n[i]][k];
    }
    /*
    printf("m:%d and:%lld\n",m+1,ans);
    REP(k,K+1) printf(" %lld",dp[m][k]);
    printf("\n");
    */
	}
  cout << ans << endl;
	return 0;
}