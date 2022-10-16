#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define N 2000004
#define ls ch[k][0]
#define rs ch[k][1]
#define mid (l+r>>1)
struct node{
	int x,y;
	inline bool operator <(node aa)const{
		return y>aa.y;
	}
}tmp,tt;
int T,n,m,i,tot,gg,rev[N],dp[N],mn[N],x,y,dis[N],ch[N][2],rt,dp_[N],a[N],b[N],j1,j2,cnt;
vector<int>to[N],val[N];
void add(int x,int y,int v=0){to[y].push_back(x);val[y].push_back(v);}
void build(int &k,int l,int r){
	if(!k)k=++tot;
	if(l==r){
		dp_[l]=k;rev[k]=l+1;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	add(k,ls);
	add(k,rs);
}
void ADD(int gg,int k,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		add(gg,k);
		return ;
	}
	if(x>r||y<l)return ;
	ADD(gg,ls,l,mid,x,y);ADD(gg,rs,mid+1,r,x,y);
}
priority_queue<node>pq;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<=n;++i)cin>>b[i];
	build(rt,0,n);
	for(i=0;i<=n;++i)dp[i]=tot+i+1;
	for(i=1;i<=n;++i){
		add(dp_[i],dp[i+b[i]],1);
		ADD(dp[i],1,0,n,i-a[i],i);
	}
	for(i=1;i<=tot+n+1;++i)dis[i]=1e9;
	dis[dp_[0]]=1;
	tmp.x=dp_[0];
	tmp.y=1;
	pq.push(tmp);
	while(pq.size()){
		tmp=pq.top();pq.pop();
		if(dis[tmp.x]^tmp.y)continue;
		x=tmp.x;y=tmp.y;
		for(i=0;i<to[x].size();++i){
			if(dis[to[x][i]]>dis[x]+val[x][i]){
				dis[to[x][i]]=dis[x]+val[x][i];
				tmp.x=to[x][i];
				tmp.y=dis[to[x][i]];
				pq.push(tmp);
				mn[tmp.x]=x;
			}
		}
	}
	if(dis[dp[n]]>n)return cout<<-1,0;
	cout<<dis[dp[n]]<<"\n";
	gg=dp[n];
	while(gg){
		gg=mn[gg];
		while(!rev[gg]){
			gg=mn[gg];
		}
		cout<<rev[gg]-1<<' ';
		gg=mn[gg];
	}
}