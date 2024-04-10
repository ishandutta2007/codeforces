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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define MOD 1000000007

stack<int> s;

char line[777];
int N, p[777];
int dp[777][777][10];

int solve(int l,int r,int state){
	if(dp[l][r][state] != -1) return dp[l][r][state];
	if(l == r) return dp[l][r][state] = 1;
	int n = p[l];
	int a = state / 3;
	int b = state % 3;
	int res = 0;
	if(a!=1) res = (res + (long long) solve(l+1,n,3*1 + 0) * solve((n+1),r,3*0 + b) ) %MOD;
	if(a!=2) res = (res + (long long) solve(l+1,n,3*2 + 0) * solve((n+1),r,3*0 + b) ) %MOD;
	if(n + 1 < r || b != 1) res = (res + (long long) solve(l+1,n,3*0 + 1) * solve((n+1),r,3*1 + b) ) %MOD;
	if(n + 1 < r || b != 2) res = (res + (long long) solve(l+1,n,3*0 + 2) * solve((n+1),r,3*2 + b) ) %MOD;
	return dp[l][r][state] = res;
}

int main(int argc, char *argv[]){
	scanf("%s",line);
	N = strlen(line);
	REP(i,N){
		if(line[i] == '(') s.push(i);
		else{
			p[s.top()] = i;
			s.pop();
		}
	}
	REP(i,N+1) REP(j,N+1) REP(k,10) dp[i][j][k] = -1;
	printf("%d\n",solve(0,N,0));
	return 0;
}