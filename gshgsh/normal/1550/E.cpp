#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
#define MAXM 17
int N,M,a[MAXN],f[1<<MAXM],pos[MAXN][MAXM];
int getc(){char c=getchar();while(c!='?'&&(c<'a'||c>'z'))c=getchar();return c!='?'?c-'a':M;}
bool check(int x)
{
	For(i,0,M-1)pos[N+1][i]=N+1;
	For(j,0,M-1){int pre=N+1;FOR(i,N,1){if(a[i]!=j&&a[i]!=M)pre=i;pos[i][j]=pos[i+1][j];if(pre-i>=x)pos[i][j]=i+x-1;}}
	For(i,1,(1<<M)-1)f[i]=N+1;For(i,0,(1<<M)-2)if(f[i]<=N)For(j,0,M-1)if(!((i>>j)&1))f[i^(1<<j)]=min(f[i^(1<<j)],pos[f[i]+1][j]);
	return f[(1<<M)-1]<=N;
}
int main()
{
	cin>>N>>M;For(i,1,N)a[i]=getc();
	int l=1,r=N/M,ans=0;while(l<=r){int mid=l+r>>1;check(mid)?ans=mid,l=mid+1:r=mid-1;}cout<<ans<<endl;return 0;
}