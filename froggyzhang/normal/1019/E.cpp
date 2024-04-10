#include<bits/stdc++.h>
using namespace std;
#define N 400011
typedef long long ll;
int n,m;
struct Point{
	ll x,y;
	Point(ll _x=0,ll _y=0){x=_x,y=_y;}
	friend Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y);
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend __int128 operator % (const Point &a,const Point &b){
		return (__int128)a.x*b.y-(__int128)a.y*b.x;
	}
};
vector<pair<int,Point> > G[N];
int head[N],ecnt=1,rt,siz[N],myh,vis[N];
struct Edge{
	int to,nxt;
	Point w;
}edge[N<<1];
void Add(int a,int b,Point c){
	edge[++ecnt]={b,head[a],c};
	head[a]=ecnt;	
}
void adde(int a,int b,Point c){
	Add(a,b,c),Add(b,a,c);
}
void get_root(int u,int fa,int total){
	siz[u]=1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa||vis[i>>1])continue;
		get_root(v,u,total);
		siz[u]+=siz[v];
		if(max(siz[v],total-siz[v])<myh||!rt){
			rt=i;myh=max(siz[v],total-siz[v]);
		}
	}
}
void dfs(int u,int fa,Point p,vector<Point> &A){
	A.push_back(p);
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[i>>1]||v==fa)continue;
		dfs(v,u,p+edge[i].w,A);
	}
}
inline bool Left(Point a,Point b){
	return b%a>0;	
}
vector<Point> Convex(vector<Point> &A){
	sort(A.begin(),A.end(),[&](Point a,Point b){return a.x==b.x?a.y<b.y:a.x<b.x;});
	vector<Point> st;
	for(auto p:A){
		while(st.size()>1&&!Left(st.back()-st[st.size()-2],p-st[st.size()-2]))st.pop_back();
		st.push_back(p);
	}
	return st;
}
vector<Point> Mink(vector<Point> &A,vector<Point> &B){
	vector<Point> C(1,A[0]+B[0]);
	int i=0,j=0;
	while(i<(int)A.size()-1||j<(int)B.size()-1){
		if(j==(int)B.size()-1||(i<(int)A.size()-1&&Left(A[i+1]-A[i],B[j+1]-B[j])))++i;
		else ++j;
		C.push_back(A[i]+B[j]);	
	}
	return C;
}
vector<Point> Solve(int md){
	vis[md>>1]=1;
	int x=edge[md].to,y=edge[md^1].to;
	vector<Point> A,B;
	dfs(x,y,0,A);
	dfs(y,x,0,B);
	A=Convex(A);
	B=Convex(B);
	A=Mink(A,B);
	for(auto &p:A)p=p+edge[md].w;
	rt=0;
	get_root(x,y,siz[x]);
	if(rt){
		auto z=Solve(rt);
		A.insert(A.end(),z.begin(),z.end());
	}
	rt=0;
	get_root(y,x,siz[y]);
	if(rt){
		auto z=Solve(rt);
		A.insert(A.end(),z.begin(),z.end());
	}
	A=Convex(A);
	return A;
}
void init(int u,int fa){
	if(fa){
		for(auto it=G[u].begin();;++it){
			if(it->first==fa){G[u].erase(it);break;}
		}	
	}
	for(auto [v,w]:G[u]){
		init(v,u);	
	}	
}
int cnt;
void rebuild(int u){
	if(G[u].size()<=2){
		for(auto [v,w]:G[u]){
			adde(u,v,w);
			rebuild(v);	
		}	
	}
	else{
		int x=++cnt,y=++cnt;
		adde(u,x,0),adde(u,y,0);
		for(int i=0;i<(int)G[u].size();++i){
			if(i&1)G[x].push_back(G[u][i]);
			else G[y].push_back(G[u][i]);
		}
		rebuild(x),rebuild(y);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;++i){
		int u,v,x,y;
		cin>>u>>v>>x>>y;
		G[u].emplace_back(v,Point(x,y));
		G[v].emplace_back(u,Point(x,y));
	}
	init(1,0);
	cnt=n;
	rebuild(1);
	get_root(1,0,n);
	auto A=Solve(rt);
	for(int i=0,j=0;i<m;++i){
		while(j<(int)A.size()-1&&i*A[j+1].x+A[j+1].y>i*A[j].x+A[j].y)++j;
		cout<<i*A[j].x+A[j].y<<' ';
	}
	return 0;
}