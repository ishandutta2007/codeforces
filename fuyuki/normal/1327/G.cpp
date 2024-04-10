#include<bits/stdc++.h>
using namespace std;
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=4e5+2,K=1e3+2;
char a[N];
vector<int>cnt[15];
ll dp[K][1<<14],d[K],ans=-1ll<<62;
int n,tot=1,len,now,ch[K][14],val[K],fa[K],t[K];
V cmax(ll&x,ll y){if(x<y)x=y;}
V input(){
	scanf("%d",&n);int x,u,*v;
	FOR(i,1,n){
		scanf("%s%d",a+1,&x),len=strlen(a+1),u=1;
		FOR(j,1,len)v=&ch[u][a[j]-'a'],!*v&&(*v=++tot),u=*v;
		val[u]+=x;
	}
}
V init(){
	FOR(i,0,13)ch[0][i]=1;int u,v;
	for(queue<int>q({1});!q.empty();q.pop()){
		v=fa[u=q.front()],val[u]+=val[v],t[u]=u;
		FOR(i,0,13)
			if(ch[u][i])fa[ch[u][i]]=ch[v][i],q.push(ch[u][i]);
			else ch[u][i]=ch[v][i];
	}
	FOR(i,0,(1<<14)-1)cnt[__builtin_popcount(i)].push_back(i);
	memset(dp,-127,sizeof(dp)),dp[1][0]=0;
}
V upd(int x,int y,ll w){cmax(dp[x][y],w+val[x]);}
V work(){
	scanf("%s",a+1),n=strlen(a+1);
	FOR(i,1,n)if(a[i]=='?'){
		for(int v:cnt[now])FOR(j,1,tot)FOR(k,0,13)if(!(v>>k&1))
			upd(ch[t[j]][k],1<<k|v,dp[j][v]+d[j]);
		FOR(j,1,tot)t[j]=j,d[j]=0;now++;
	}
	else FOR(j,1,tot)t[j]=ch[t[j]][a[i]-'a'],d[j]+=val[t[j]];
	for(int v:cnt[now])FOR(i,1,tot)cmax(ans,dp[i][v]+d[i]);
	cout<<ans;
}
int main(){
	input();
	init();
	work();
	return 0;
}