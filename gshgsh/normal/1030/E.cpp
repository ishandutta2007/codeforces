#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,a[MAXN],s[MAXN];ll ans;
ll get(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int cnt(ll x){int ans=0;while(x)x-=x&-x,ans++;return ans;}
int main()
{
	N=get();For(i,1,N)a[i]=cnt(get()),s[i]=s[i-1]^(a[i]&1);int c[2]={1,0};For(i,1,N)ans+=c[s[i]]++;
	For(i,1,N){int sum=0,mx=0;For(j,i,min(i+60,N)){sum+=a[j],mx=max(mx,a[j]);if(!(sum&1)&&mx*2>sum)ans--;}}cout<<ans<<'\n';return 0;
}