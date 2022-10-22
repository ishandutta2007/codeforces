#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 100001
int N=MAXN-1,M,cnt[MAXN],res[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,ll b){if(b<0)return 0;int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	M=get();For(i,1,M){int x=get();cnt[x]=get();}
	FOR(i,N,1)
	{
		ll c=0;for(int j=i;j<=N;j+=i)c+=cnt[j];if(c<2)continue;
		int v1=(c-1)%P*pow(2,c-2)%P,v2=((c-2)%P*pow(2,c-3)%P+pow(2,c-2))%P;
		int sum=0;for(int j=i;j<=N;j+=i)sum=(sum+1ll*j*cnt[j])%P;
		for(int j=i;j<=N;j+=i)res[i]=(res[i]+1ll*j*j%P*cnt[j]%P*v1)%P;
		for(int j=i;j<=N;j+=i)res[i]=(res[i]+1ll*j*j%P*cnt[j]%P*(cnt[j]-1)%P*v2)%P;
		for(int j=i;j<=N;j+=i)res[i]=(res[i]+1ll*j*cnt[j]%P*(sum-1ll*j*cnt[j]%P+P)%P*v2)%P;
		for(int j=i*2;j<=N;j+=i)res[i]=(res[i]-res[j]+P)%P;
	}
	cout<<res[1]<<'\n';
}