#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 300001
int N,a[MAXN];ll sum[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	N=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1);For(i,1,N)sum[i]=sum[i-1]+a[i];
	FOR(i,N-1,0){ll ans=0;int x=i,j=1;while(x>0)ans=(ans+(sum[x]-sum[max(x-N+i,0)])%P*j)%P,x-=N-i,j++;cout<<1ll*ans*pow(N,P-2)%P<<" \n"[!i];}return 0;
}