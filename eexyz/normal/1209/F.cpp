#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 200005
int dis[N],nd[N],ss[12],ttt,node[N],cnt,tot,fa[N<<3][22],to[N<<3][10],n,m,tt[N],nxt[N],val[N];
struct Node{
	int x,y;
	bool operator<(Node aa)const{
		return y>aa.y;
	}
}tmp;
vector<int>fr[N],VV[N];
inline Node mk(int x,int y){tmp.x=x;tmp.y=y;return tmp;}
priority_queue<Node>q;
inline bool cmp(int aa,int bb){
	return dis[aa]<dis[bb];
}
int add(int x,int y){
//	cout<<x<<' '<<y<<"\n";
	cnt=0;while(y)ss[++cnt]=y%10,y/=10;
	int i;
	for(i=cnt;i;x=to[x][ss[i]],--i)
		if(!to[x][ss[i]]){
			to[x][ss[i]]=++ttt;fa[ttt][0]=x;
			for(int ii=1;ii<=20;++ii)
				fa[ttt][ii]=fa[fa[ttt][ii-1]][ii-1];
		}
	return x;
}
bool CMP(int x,int y){
	for(int i=20;~i;--i)
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	for(int i=0;i<10;++i){
		if(to[fa[x][0]][i]==x)return 0;
		if(to[fa[x][0]][i]==y)return 1;
	}
}
int i,gg[N],x,j,u[N],pos[N],now,y,X[N],Y[N],ot[N];
void dfs(int now){
	for(int i=0;i<=9;++i){
		if(to[now][i]){
			ot[to[now][i]]=(1ll*ot[now]*10+i)%mod;
			dfs(to[now][i]);
		}
	}
}
int main(){
	cin>>n>>m;
	for(i=1;i<=m;++i)gg[i]=gg[i/10]+1;
	for(i=1;i<=m;++i){
		cin>>x>>y;
		tt[++tot]=y;
		nxt[tot]=node[x];
		val[tot]=gg[i];
		node[x]=tot;
		tt[++tot]=x;
		nxt[tot]=node[y];
		val[tot]=gg[i];
		node[y]=tot;
		X[i]=x;Y[i]=y;
	}
	q.push(mk(1,0));
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	while(q.size()){
		tmp=q.top();q.pop();
		if(dis[tmp.x]!=tmp.y)continue;
		x=tmp.x;
		for(i=node[x];i;i=nxt[i])
			if(dis[tt[i]]>dis[x]+val[i])
				q.push(mk(tt[i],dis[tt[i]]=dis[x]+val[i]));
	}
	for(i=1;i<=m;++i){
		if(dis[Y[i]]<dis[X[i]])swap(X[i],Y[i]);
		if(dis[X[i]]+gg[i]==dis[Y[i]]){
//			cout<<X[i]<<" "<<Y[i]<<"\n";
			fr[Y[i]].push_back(X[i]);
			VV[Y[i]].push_back(i);
		}
	}
	for(i=1;i<=n;++i)gg[i]=i;
	sort(gg+1,gg+n+1,cmp);
	for(i=2;i<=n;++i){
		j=gg[i];tot=0;//cout<<j<<"\n"; 
		for(x=0;x<fr[j].size();++x)
			pos[++tot]=add(u[fr[j][x]],VV[j][x]);
		now=pos[1];
		for(x=2;x<=tot;++x)
			if(CMP(now,pos[x]))now=pos[x];
		u[j]=now;
	}
	dfs(0);
	for(i=2;i<=n;++i)
		cout<<ot[u[i]]<<"\n";
	return 0;
}