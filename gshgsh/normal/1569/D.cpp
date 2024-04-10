#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
#define MAXK 300001
int T,N,M,K,x[MAXN],y[MAXN],dx[MAXK],dy[MAXK];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get(),K=get();For(i,1,N)x[i]=get();For(i,1,M)y[i]=get();
		map<int,int>cntx1,cnty1;map<int,map<int,int>>cntx2,cnty2;ll ans=0;
		For(i,1,K)
		{
			int a=get(),b=get(),c=lower_bound(x+1,x+N+1,a)-x,d=lower_bound(y+1,y+M+1,b)-y;if(x[c]==a&&y[d]==b)continue;
			if(x[c]!=a)ans+=cntx1[c]-cntx2[c][d],cntx1[c]++,cntx2[c][d]++;
			else ans+=cnty1[d]-cnty2[d][c],cnty1[d]++,cnty2[d][c]++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}