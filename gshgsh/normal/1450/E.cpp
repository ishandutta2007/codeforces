#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 201
#define MAXM 2001
int N,M,u[MAXM],v[MAXM],dis[MAXN][MAXN],ans,id=1;
int main()
{
	cin>>N>>M;memset(dis,0x3f,sizeof(dis));For(i,1,N)dis[i][i]=0;For(i,1,M){int x;cin>>u[i]>>v[i]>>x;dis[u[i]][v[i]]=1;dis[v[i]][u[i]]=x?-1:1;}
	For(k,1,N)For(i,1,N)For(j,1,N)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);For(i,1,N){if(dis[i][i]<0){cout<<"NO\n";return 0;}For(j,1,N)if(ans<dis[i][j])ans=dis[i][j],id=i;}
	For(i,1,M)if(dis[id][u[i]]==dis[id][v[i]]){cout<<"NO\n";return 0;}cout<<"YES\n"<<ans<<endl;For(i,1,N)cout<<dis[id][i]<<' ';return 0;
}