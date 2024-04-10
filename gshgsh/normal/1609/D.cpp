#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int N,M,x[MAXN],y[MAXN],f[MAXN],siz[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}void mrg(int x,int y){x=getf(x),y=getf(y);if(x!=y)f[x]=y,siz[y]+=siz[x];}
int main()
{
	N=get(),M=get();For(i,1,M)x[i]=get(),y[i]=get();
	For(i,1,M)
	{
		For(j,1,N)f[j]=j,siz[j]=1;For(j,1,i)mrg(x[j],y[j]);vector<int>a;For(j,1,N)if(siz[getf(j)])a.push_back(siz[getf(j)]),siz[getf(j)]=0;
		sort(a.begin(),a.end(),greater<int>());int cnt=0;for(auto j:a)cnt+=j-1;
		int tot=a.size();int ans=a[0]-1;For(j,1,min(tot-1,i-cnt))ans+=a[j];cout<<ans<<'\n';
	}
	return 0;
}