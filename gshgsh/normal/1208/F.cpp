#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1<<21
int N,a[MAXN],mx[MAXN],mx2[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int x,int v){if(mx[x]<v)mx2[x]=mx[x],mx[x]=v;else if(mx2[x]<v)mx2[x]=v;}
int main()
{
	N=get();For(i,1,N)a[i]=get(),upd(a[i],i);For(i,0,20)For(j,0,(1<<21)-1)if(j>>i&1)upd(j^1<<i,mx[j]),upd(j^1<<i,mx2[j]);
	int ans=0;For(i,1,N-2){int x=0;FOR(j,20,0)if(!(a[i]>>j&1))if(mx2[x^1<<j]>i)x^=1<<j;ans=max(ans,a[i]^x);}cout<<ans<<'\n';
}