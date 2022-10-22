#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,M,a[MAXN],b[MAXN],nxt[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get();For(i,1,N)a[i]=get();For(i,1,M)b[i]=get();
	if(M==1){cout<<N<<'\n';return 0;}if(N<M){cout<<"0\n";return 0;}
	N--;For(i,1,N)a[i]=a[i+1]-a[i];M--;For(i,1,M)b[i]=b[i+1]-b[i];
	int j=0;For(i,2,M){while(j&&b[j+1]!=b[i])j=nxt[j];j+=b[j+1]==b[i];nxt[i]=j;}
	int ans=0;j=0;For(i,1,N){while(j&&b[j+1]!=a[i])j=nxt[j];j+=b[j+1]==a[i];ans+=j==M;}cout<<ans<<'\n';return 0;
}