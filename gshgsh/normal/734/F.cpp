#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,a[MAXN],b[MAXN],c[MAXN],cnt[32];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)b[i]=get();For(i,1,N)c[i]=get();
	ll sum=0;For(i,1,N)sum+=b[i]+c[i];if(sum%(N*2)){cout<<"-1\n";return 0;}sum/=N*2;
	For(i,1,N)if((b[i]+c[i]-sum)%N){cout<<"-1\n";return 0;}else a[i]=(b[i]+c[i]-sum)/N;
	For(i,1,N)For(j,0,31)cnt[j]+=a[i]>>j&1;
	For(i,1,N){ll x=0,y=0;For(j,0,31)if(a[i]>>j&1)x+=1ll*cnt[j]<<j,y+=1ll*N<<j;else y+=1ll*cnt[j]<<j;if(x!=b[i]||y!=c[i]){cout<<"-1\n";return 0;}}
	For(i,1,N)cout<<a[i]<<" \n"[i==N];
}