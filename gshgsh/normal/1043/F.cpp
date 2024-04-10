#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll __int128
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,a[MAXN],c[MAXN],cnt[MAXN];ll f[MAXN],g[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
ll C(int x,int y){if(x<y)return 0;ll ans=1;For(i,x-y+1,x)ans*=i;For(i,1,y)ans/=i;return ans;}
int main()
{
	N=get();For(i,1,N)c[a[i]=get()]++;int x=a[1];For(i,2,N)x=__gcd(x,a[i]);if(x>1){cout<<"-1\n";return 0;}FOR(i,300000,1)for(int j=i;j<=300000;j+=i)cnt[i]+=c[j];
	For(k,1,7){FOR(i,300000,1){f[i]=C(cnt[i],k);for(int j=i*2;j<=300000;j+=i)f[i]-=f[j];}if(f[1]){cout<<k<<'\n';return 0;}}return 0;
}