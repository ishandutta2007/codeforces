#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 101
int N,M,b[MAXN],c[MAXN],sb[MAXN],sc[MAXN],mul;map<int,int>ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int solve(int x)
{
	vector<vector<int> >f(N+1),g(N+1);For(i,0,N)f[i].resize(sc[min(i+1,N)]+1),g[i].resize(sc[min(i+1,N)]+1);For(i,0,sc[1])g[0][i]=1;
	For(i,1,N){For(j,max(x*i+sb[i],0),sc[i])f[i][j]=(g[i-1][j]-(j>c[i]?g[i-1][j-c[i]-1]:0)+P)%P;g[i][0]=f[i][0];For(j,1,sc[min(i+1,N)])g[i][j]=(g[i][j-1]+f[i][j])%P;}return g[N][sc[N]];
}
int main()
{
	N=get();mul=1;For(i,1,N)c[i]=get(),mul=1ll*mul*(c[i]+1)%P,sc[i]=sc[i-1]+c[i];For(i,1,N-1)b[i]=get();For(i,1,N)For(j,1,i-1)sb[i]+=(i-j)*b[j];
	int l=100000;For(i,1,N)l=min(l,-sb[i]/i-1);int r=l-1;do r++,ans[r]=solve(r);while(ans[r]);
	M=get();For(i,1,M){int x=get();if(x>=l&&x<=r)cout<<ans[x]<<endl;else if(x<l)cout<<mul<<endl;else cout<<"0\n";}return 0;
}