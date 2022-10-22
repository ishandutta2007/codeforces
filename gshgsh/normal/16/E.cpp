#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 18
int N;double a[MAXN][MAXN],f[1<<MAXN];
int cnt(int x){int cnt=0;while(x)x-=lowbit(x),cnt++;return cnt;}
int main()
{
	cin>>N;For(i,0,N-1)For(j,0,N-1)cin>>a[i][j];f[(1<<N)-1]=1;
	FOR(i,(1<<N)-2,1)For(j,0,N-1)if(!((i>>j)&1))For(k,0,N-1)if((i>>k)&1)f[i]+=f[i|(1<<j)]*a[k][j]*2/cnt(i)/(cnt(i)+1);
	For(i,0,N-1)printf("%.6lf ",f[1<<i]);return 0;
}