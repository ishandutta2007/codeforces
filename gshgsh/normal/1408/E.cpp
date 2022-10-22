#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define Tair pair<int,Pair>
#define F first
#define S second
#define MAXN 100001
int M,N,K,a[MAXN],b[MAXN],f[MAXN*2];Tair E[MAXN*2];ll ans;int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	M=get(),N=get();For(i,1,M)a[i]=get();For(i,1,N)b[i]=get();For(i,1,M){int k=get();while(k--){int x=get();E[++K]={a[i]+b[x],{i,x+M}},ans+=a[i]+b[x];}}For(i,1,N+M)f[i]=i;
	sort(E+1,E+K+1,greater<Tair>());For(i,1,K)if(getf(E[i].S.F)!=getf(E[i].S.S))ans-=E[i].F,f[getf(E[i].S.F)]=getf(E[i].S.S);cout<<ans<<endl;return 0;
}