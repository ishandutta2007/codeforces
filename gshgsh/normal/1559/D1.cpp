#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int N,f[MAXN][2];int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x,int y){return f[x][y]==x?x:f[x][y]=getf(f[x][y],y);}
int main()
{
	N=get();For(i,1,N)f[i][0]=f[i][1]=i;int M1=get(),M2=get();For(i,1,M1)f[getf(get(),0)][0]=getf(get(),0);For(i,1,M2)f[getf(get(),1)][1]=getf(get(),1);
	vector<pair<int,int>>ans;For(i,1,N)For(j,i+1,N){int a=getf(i,0),b=getf(j,0),x=getf(i,1),y=getf(j,1);if(a!=b&&x!=y)f[a][0]=b,f[x][1]=y,ans.push_back({i,j});}
	cout<<ans.size()<<'\n';for(auto i:ans)cout<<i.first<<' '<<i.second<<'\n';return 0;
}