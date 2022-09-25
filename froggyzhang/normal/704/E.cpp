#include<bits/stdc++.h>
using namespace std;
#define N 300010
typedef long long ll;
const double eps=1e-8;
const double inf=1e18;
inline int dcmp(double x){
	return (x>-eps)-(x<eps);
}
struct Point{
	double x,y;
	Point(double _x=0,double _y=0){x=_x,y=_y;}
	friend Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y);	
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);	
	}
	friend Point operator * (const Point &a,const double &k){
		return Point(a.x*k,a.y*k);	
	}
	friend double operator % (const Point &a,const Point &b){
		return a.x*b.y-a.y*b.x;	
	}
	friend bool operator == (const Point &a,const Point &b){
		return !dcmp(a.x-b.x)&&!dcmp(a.y-b.y);
	}
};
double nowx;
struct Line{
	Point p[2];
	Line(Point a,Point b){p[0]=a,p[1]=b;}
	Point & operator [] (int x){
		return p[x];
	}
};
double Go(Line a,double X){
	return (a[0]+(a[1]-a[0])*((X-a[0].x)/(a[1].x-a[0].x))).y;
}
bool operator < (const Line &a,const Line &b){
	return Go(a,nowx)<Go(b,nowx);	
}
int n,m,top[N],son[N],siz[N],f[N],dep[N];
vector<int> G[N];
void dfs1(int u){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}	
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);	
	}	
}
int LCA(int u,int v){
	while(top[u]^top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=f[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	return u;
}
double Inter(Line a,Line b){
	if(a[0]==a[1])swap(a,b);
	if(!dcmp((a[1]-a[0])%(b[0]-a[0]))&&!dcmp((a[1]-a[0])%(b[1]-a[0]))){
		return max(a[0].x,b[0].x)<=min(a[1].x,b[1].x)?max(a[0].x,b[0].x):inf;
	}
	if(a[0]==a[1]||b[0]==b[1])return inf;
	if(dcmp((b[1]-b[0])%(a[0]-b[0]))*dcmp((b[1]-b[0])%(a[1]-b[0]))<=0&&dcmp((a[1]-a[0])%(b[0]-a[0]))*dcmp((a[1]-a[0])%(b[1]-a[0]))<=0){
		return (a[0]+(a[1]-a[0])*fabs((((b[0]-a[0])%(b[1]-a[0]))/((a[1]-a[0])%(b[1]-b[0]))))).x;
	}
	return inf;
}
vector<Line> P[N];
struct Event{
	double t;
	int op,id;
	Event(double _t,int _op,int _id):t(_t),op(_op),id(_id){};
};
double Solve(vector<Line> &P){
	double mn=inf;
	vector<Event> E;
	for(int i=0;i<(int)P.size();++i){
		E.emplace_back(P[i][0].x,1,i);
		E.emplace_back(P[i][1].x,0,i);	
	}
	sort(E.begin(),E.end(),[&](Event a,Event b){return !dcmp(a.t-b.t)?a.op>b.op:a.t<b.t;});
	static multiset<Line> S;
	static multiset<Line>::iterator it[N];
	S.clear();
	for(auto myh:E){
		double t=myh.t;
		int id=myh.id,op=myh.op;
		nowx=t;
		if(op){
			it[id]=S.insert(P[id]);
			auto u=it[id];
			if(u!=S.begin())mn=min(mn,Inter(*prev(u),P[id]));
			++u;
			if(u!=S.end()){
				mn=min(mn,Inter(P[id],*u));
			}
		}
		else{
			auto u=it[id];
			if(u!=S.begin()&&next(u)!=S.end()){
				mn=min(mn,Inter(*prev(u),*next(u)));	
			}
			S.erase(it[id]);
		}	
	}
	/*
	for(int i=0;i<(int)P.size();++i){
		for(int j=i+1;j<(int)P.size();++j){
			mn=min(mn,Inter(P[i],P[j]));
		}
	}
	*/
	return mn;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(6);
	cin>>n>>m;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=m;++i){
		int t,sp,u,v;
		cin>>t>>sp>>u>>v;
		int lca=LCA(u,v);
		int len=dep[u]+dep[v]-2*dep[lca];
		double l=t,r=t+1.0*len/sp;
		auto Get=[&](int u)->double{
			return dep[u]-dep[top[u]]+1;	
		};
		while(top[u]^top[v]){
			if(dep[top[u]]<=dep[top[v]]){
				double z=Get(v)/sp;
				P[top[v]].emplace_back(Point(r-z,0),Point(r,Get(v)));
				r-=z,v=f[top[v]];
			}
			else{
				double z=Get(u)/sp;
				P[top[u]].emplace_back(Point(l,Get(u)),Point(l+z,0));
				l+=z,u=f[top[u]];
			}
		}	
		P[top[u]].emplace_back(Point(l,Get(u)),Point(r,Get(v)));
	}
	double ans=inf;
	for(int i=1;i<=n;++i){
		if(top[i]==i){
			ans=min(ans,Solve(P[i]));	
		}
	}
	cout<<(!dcmp(ans-inf)?-1:ans)<<'\n';
	return 0;
}