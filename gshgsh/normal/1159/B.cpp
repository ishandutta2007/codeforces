#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,a[MAXN],p[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get(),p[i]=i;sort(p+1,p+N+1,[](int x,int y){return a[x]<a[y];});
	int ans=1e9,l=1,r=N;For(i,1,N){int x=a[p[i]];while(l<=r&&a[l]<x)l++;while(l<=r&&a[r]<x)r--;if(l<p[i])ans=min(ans,x/(p[i]-l));if(r>p[i])ans=min(ans,x/(r-p[i]));}cout<<ans<<'\n';return 0;
}