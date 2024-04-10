#include<iostream>
#include<unordered_map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
#define MAXM 10000001
int T,N,M,a[MAXN],tot,prm[MAXM],Div[MAXM];bool Not[MAXM];
int turn(int x){int y=x;while(x!=1){int tmp=Div[x];while(x%tmp==0)x/=tmp;while(y%(1ll*tmp*tmp)==0)y/=tmp*tmp;}return y;}
int main()
{
	M=MAXM-1;For(i,2,M){if(!Not[i])prm[++tot]=i,Div[i]=i;for(int j=1;j<=tot&&i*prm[j]<=M;j++){Not[i*prm[j]]=1;Div[i*prm[j]]=prm[j];if(i%prm[j]==0)break;}}cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,1,N)cin>>a[i],M=max(M,a[i]);unordered_map<int,bool>vis;vis[turn(a[1])]=1;int ans=1;
		For(i,2,N){int x=turn(a[i]);if(vis[x])vis.clear(),ans++;vis[x]=1;}cout<<ans<<endl;
	}
	return 0;
}