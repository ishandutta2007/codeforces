#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 1000001
int N,a[MAXN],f[MAXN],cnt[MAXN];vector<int>Div[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get();
	For(i,1,MAXN-1)for(int j=i;j<MAXN;j+=i)cnt[j]++;For(i,1,MAXN-1)Div[i].resize(cnt[i]);
	For(i,1,MAXN-1)for(int j=i;j<MAXN;j+=i)Div[j][--cnt[j]]=i;
	f[0]=1;For(i,1,N)for(auto j:Div[a[i]])f[j]=(f[j]+f[j-1])%P;
	int ans=0;For(i,1,N)ans=(ans+f[i])%P;cout<<ans<<'\n';return 0;
}