#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 3000001
int T,N,M,p1[MAXN],p2[MAXN],*a[MAXN],*b[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)a[i]=p1+(i-1)*(M+2)+1,b[i]=p2+(i-1)*(M+2)+1;
		For(i,1,N)For(j,1,M)a[i][j]=get(),b[i][j]=a[i][j];For(i,1,N)sort(b[i]+1,b[i]+M+1);
		int x=1,y=1;bool flag=1;
		For(i,1,N)
		{
			vector<int>p;
			For(j,1,M)if(a[i][j]!=b[i][j])p.push_back(j);
			if(p.size()>2){flag=0;break;}
			if(p.size()<2)continue;
			int xx=p[0],yy=p[1];if(xx>yy)swap(xx,yy);
			if(x!=y&&(x!=xx||y!=yy)){flag=0;break;}x=xx,y=yy;
		}
		if(x!=y)For(i,1,N)if(a[i][x]<a[i][y]){flag=0;break;}
		if(!flag)cout<<"-1\n";else cout<<x<<' '<<y<<'\n';
	}
}