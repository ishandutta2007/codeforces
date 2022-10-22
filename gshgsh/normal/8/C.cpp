#include<iostream>
#include<cstring>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define F first
#define S second
#define MAXN 24
int N,a,b,x[MAXN],y[MAXN],dis[MAXN][MAXN],dis0[MAXN],f[1<<MAXN];Pair pre[1<<MAXN];
int main()
{
    cin>>a>>b>>N;For(i,0,N-1)cin>>x[i]>>y[i],dis0[i]=(x[i]-a)*(x[i]-a)+(y[i]-b)*(y[i]-b);For(i,0,N-1)For(j,0,N-1)dis[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    memset(f,0x3f,sizeof(f));f[0]=0;For(i,0,(1<<N)-2){int x=0;while((i>>x)&1)x++;For(j,x,N-1)if(!((i>>j)&1)&&f[i|(1<<x)|(1<<j)]>f[i]+dis0[x]+dis0[j]+dis[x][j])f[i|(1<<x)|(1<<j)]=f[i]+dis0[x]+dis0[j]+dis[x][j],pre[i|(1<<x)|(1<<j)]={x,j};}
    cout<<f[(1<<N)-1]<<endl;int i=(1<<N)-1;cout<<"0 ";while(i){int x=pre[i].F,y=pre[i].S;if(x==y)cout<<x+1<<" 0 ";else cout<<x+1<<' '<<y+1<<" 0 ";i&=(1<<N)-1^(1<<x),i&=(1<<N)-1^(1<<y);}return 0;
}