#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 200001
int N,l[MAXN],r[MAXN],x[MAXN],y[MAXN],f[MAXN],g[MAXN],h[MAXN],len[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	N=get();For(i,1,N)l[i]=get();For(i,1,N)r[i]=get(),len[i]=r[i]-l[i]+1;For(i,1,N-1)x[i]=max(l[i],l[i+1]),y[i]=max(x[i]-1,min(r[i],r[i+1]));f[1]=g[1]=len[1],h[1]=y[1]-x[1]+1;
	For(i,2,N)
	{
		int t=pow(len[i-1],P-2);
		f[i]=(1ll*len[i]*f[i-1]%P*t%P+len[i]-1ll*(y[i-1]-x[i-1]+1)*t%P+P)%P;
		g[i]=(1ll*len[i]*(g[i-1]+2ll*f[i-1]%P)%P*t%P+len[i]-1ll*(y[i-1]-x[i-1]+1)*t%P+P-2ll*h[i-1]*t%P+P)%P;
		if(y[i]>=x[i])h[i]=(1ll*(y[i]-x[i]+1)*t%P*(f[i-1]+len[i-1])%P-1ll*(max(max(l[i-1],x[i])-1,min(r[i-1],y[i]))-max(l[i-1],x[i])+1)*t%P+P)%P;
	}
	cout<<1ll*g[N]*pow(len[N],P-2)%P<<'\n';
}