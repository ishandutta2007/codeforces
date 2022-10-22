#include<iostream>
#include<bitset>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 10001
#define MAXM 2001
int T,N,K,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check(int x){bitset<MAXM>f,Lmt;For(i,0,x)Lmt[i]=1;f=Lmt;For(i,1,N)f=((f>>a[i])|(f<<a[i]))&Lmt;return f.any();}
int main(){T=get();while(T--){N=get(),K=0;For(i,1,N)K=max(K,a[i]=get());int l=1,r=K*2,ans=r;while(l<=r){int mid=l+r>>1;check(mid)?ans=mid,r=mid-1:l=mid+1;}cout<<ans<<'\n';}return 0;}