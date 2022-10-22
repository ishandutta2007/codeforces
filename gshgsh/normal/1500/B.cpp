#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffffffffffff
#define MAXN 500001
int N,M,a[MAXN],b[MAXN],pos[MAXN*2],K;ll Q,t[MAXN];
ll get(){ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int GCD(int a,int b){return b?GCD(b,a%b):a;}
void EXGCD(int a,int b,ll&x,ll&y){b?EXGCD(b,a%b,y,x),y-=a/b*x:(x=1,y=0);}
ll check(ll x){ll cnt=1ll*N*M/GCD(N,M),ans=0;For(i,1,K)ans+=(x-t[i]+cnt)/cnt;return x+1-ans;}
int main()
{
	N=get(),M=get(),Q=get();For(i,0,N-1)a[i]=get(),pos[a[i]]=-1;For(i,0,M-1)pos[b[i]=get()]=i;
	For(i,0,N-1)if(pos[a[i]]!=-1&&(pos[a[i]]-i)%GCD(N,M)==0){ll x,y,d=GCD(N,M);EXGCD(N,M,x,y);x=(x%M+M)%M;x=(1ll*x*(pos[a[i]]-i)/d%(M/d)+(M/d))%(M/d);t[++K]=i+1ll*N*x;}
	sort(t+1,t+K+1);ll l=0,r=INF,ans=INF;while(l<=r){ll mid=l+r>>1;check(mid)>=Q?ans=mid,r=mid-1:l=mid+1;}cout<<ans+1<<endl;return 0;
}