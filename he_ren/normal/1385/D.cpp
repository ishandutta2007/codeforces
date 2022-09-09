#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int MAXN = 1.4e5 + 5;
const int LB = 17 + 5;
const int inf = 0x3f3f3f3f;

int lb[MAXN];

int n;
char s[MAXN];

int f[MAXN][LB];
int gao(int pos,int k)
{
	if(~f[pos][k]) return f[pos][k];
	if(k == lb[n]) return f[pos][k] = (s[pos] != k + 'a');
	int &res = f[pos][k] = inf;
	
	int half = 1<<(lb[n]-k - 1);
	
	int sum = 0;
	for(int i=0; i<half; ++i)
		sum += (s[pos+i] != k + 'a');
	res = min(res, sum + gao(pos+half, k+1));
	
	sum = 0;
	for(int i=0; i<half; ++i)
		sum += (s[pos+half+i] != k + 'a');
	res = min(res, sum + gao(pos, k+1));
	
	return res;
}

void solve(void)
{
	scanf("%d%s",&n,s+1);
	
	for(int i=1; i<=n; ++i)
		for(int j=0; j<=lb[n]; ++j)
			f[i][j] = -1;
	printf("%d\n",gao(1,0));
}

int main(void)
{
	lb[1] = 0;
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}