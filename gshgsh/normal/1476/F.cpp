#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int T,N,a[MAXN],f[MAXN],st[MAXN][20],type[MAXN],pre[MAXN],ans[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int ask(int l,int r){if(l>r)return 0;int k=log2(r-l+1);return max(st[l][k],st[r-(1<<k)+1][k]);}
void print(int x){if(!x)return;print(pre[x]);if(type[x])cout<<'R';else{For(j,pre[x]+1,x-1)cout<<'R';cout<<'L';}}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get(),st[i][0]=a[i]+i;for(int j=1;1<<j<=N;j++)For(i,1,N-(1<<j)+1)st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		For(i,2,N)
		{
			if(f[i-1]>=i)type[i]=1,f[i]=max(f[i-1],min(i+a[i],N)),pre[i]=i-1;else f[i]=f[i-1],type[i]=1,pre[i]=i-1;
			if(i-a[i]-1>f[i-1])continue;int l=0,r=i-1,p=i-1;while(l<=r){int mid=l+r>>1;f[mid]>=i-a[i]-1?p=mid,r=mid-1:l=mid+1;}
			int v=min(N,max(i-1,ask(p+1,i-1)));if(v>f[i])f[i]=v,type[i]=0,pre[i]=p;
		}
		if(f[N]<N){cout<<"NO\n";continue;}cout<<"YES\n";print(N);cout<<'\n';
	}
}