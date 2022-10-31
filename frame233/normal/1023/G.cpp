#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef std::pair<int,int> pi;
std::vector<pi> e[N];
struct node{int d,p;inline bool operator < (const node &o)const{return d>o.d;}};
struct DS{
	std::map<int,int> a,b;std::priority_queue<node> q;int tag;
	inline int size(){return SZ(a)+SZ(b);}
	void fix(int x,int opt){
		if(opt==1){
			auto it=b.upper_bound(x-2*tag);
			if(it!=b.begin())--it,q.push({x-it->first,x});
		}
		else{
			auto it=a.lower_bound(x+2*tag);
			if(it!=a.end())q.push({it->first-x,it->first});
		}
	}
	void move(int t){
		while(!q.empty()&&q.top().d<=2*(tag+t)){
			int x=q.top().p,y=x-q.top().d;q.pop();
			auto itx=a.find(x),ity=b.find(y);
			if(itx==a.end()||ity==b.end())continue;
			if(itx->second+ity->second>0)itx->second+=ity->second,b.erase(ity),fix(x,1);
			else ity->second+=itx->second,a.erase(itx),fix(y,-1);
		}
		tag+=t;
	}
	void add(int p,int c){
		if(c>0)a[p+tag]+=c,fix(p+tag,1);
		else b[p-tag]+=c,fix(p-tag,-1);
	}
	int get(int p){
		auto it1=a.find(p+tag),it2=b.find(p-tag);
		return (it1==a.end()?0:it1->second)+(it2==b.end()?0:it2->second);
	}
}f[N];
std::vector<node> Q[N];
void dfs(int x,int fa){
	for(const auto &it:e[x])if(it.first!=fa){
		int v=it.first,w=it.second;dfs(v,x);
		for(auto &&it:Q[v])it.p-=std::max({0,f[v].get(it.d+1),-f[v].get(it.d)});
		f[v].move(1);for(const auto &it:Q[v])if(it.p>0)f[v].add(it.d,it.p),f[v].add(it.d+1,-it.p);
		f[v].move(w-1);if(f[v].size()>f[x].size())std::swap(f[x],f[v]);
		for(const auto &it:f[v].a)f[x].add(it.first-f[v].tag,it.second);
		for(const auto &it:f[v].b)f[x].add(it.first+f[v].tag,it.second);
	}
}
int main(){
	int n;read(n);for(int i=1,x,y,z;i<n;++i)read(x,y,z),z*=2,e[x].pb({y,z}),e[y].pb({x,z});
	int k;read(k);for(int i=1,x,y,z;i<=k;++i)read(x,y,z),x*=2,Q[z].pb({x,y});
	int rt=n+1;e[1].pb({rt,2}),e[rt].pb({1,2});dfs(rt,0);std::map<int,int> mp;
	for(const auto &it:f[rt].a)mp[it.first-f[rt].tag]+=it.second;
	for(const auto &it:f[rt].b)mp[it.first+f[rt].tag]+=it.second;
	int ans=0,s=0;for(const auto &it:mp)s+=it.second,ans=std::max(ans,s);
	printf("%d\n",ans);
	return 0;
}