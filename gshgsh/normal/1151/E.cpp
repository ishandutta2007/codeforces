#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,a[MAXN];ll ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main(){N=get();For(i,1,N)a[i]=get();For(i,1,N)ans+=1ll*a[i]*(N-a[i]+1);For(i,2,N)ans-=1ll*min(a[i-1],a[i])*(N-max(a[i-1],a[i])+1);cout<<ans<<'\n';return 0;}