#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=100005;typedef std::pair<int,int> pi;typedef long long ll;
std::map<pi,int> mp;
struct edge{
	int u,v,w;
	inline bool operator == (const edge &o)const{return u==o.u&&v==o.v&&w==o.w;}
	inline bool operator < (const edge &o)const{return w==o.w?v==o.v?u<o.u:v<o.v:w<o.w;}
};
std::map<edge,int> MP;std::set<edge> e[N],all;
std::vector<edge> get(int u){
	std::vector<edge> cur;
	auto it=e[u].begin();
	if(it!=e[u].end()){cur.pb(*it);
	if(++it!=e[u].end()){cur.pb(*it);
	if(++it!=e[u].end())cur.pb(*it);}}
	return cur;
}
void upd(int opt,int u,int v,int w){
	std::vector<edge> ou=get(u),ov=get(v);
	if(opt==0)e[u].insert({u,v,w}),e[v].insert({u,v,w});
	else e[u].erase({u,v,w}),e[v].erase({u,v,w});
	std::vector<edge> cu=get(u),cv=get(v);
	for(const auto &it:ou)if(std::find(cu.begin(),cu.end(),it)==cu.end())if(--MP[it]==1)all.erase(it);
	for(const auto &it:ov)if(std::find(cv.begin(),cv.end(),it)==cv.end())if(--MP[it])all.erase(it);
	for(const auto &it:cu)if(std::find(ou.begin(),ou.end(),it)==ou.end())if(++MP[it]==2)all.insert(it);
	for(const auto &it:cv)if(std::find(ov.begin(),ov.end(),it)==ov.end())if(++MP[it]==2)all.insert(it);
}
bool check(const edge &a,const edge &b,const edge &c){
	std::vector<int> v={a.u,a.v,b.u,b.v,c.u,c.v};
	std::sort(v.begin(),v.end()),v.erase(std::unique(v.begin(),v.end()),v.end());
	return SZ(v)>3;
}
ll getans(){
	std::vector<edge> v;int c=0;for(const auto &it:all){v.pb(it);if(++c==8)break;}
	ll ans=(ll)v[0].w+v[1].w+(check(v[0],v[1],v[2])?v[2].w:v[3].w);
	for(int i=0;i<SZ(v);++i)for(int j=i+1;j<SZ(v);++j){
		edge A=v[i],B=v[j];
		if(A.u!=B.u&&A.u!=B.v&&A.v!=B.u&&A.v!=B.v)chmin(ans,(ll)A.w+B.w);
	}
	return ans;
}
int main(){
	int n,m;read(n,m);
	int u,v,w;
	for(int i=1;i<=m;++i){
		read(u,v,w);if(u>v)std::swap(u,v);
		upd(0,u,v,w),mp[{u,v}]=w;
	}
	printf("%lld\n",getans());
	int opt,q;read(q);
	while(q--){
		read(opt,u,v);if(u>v)std::swap(u,v);
		if(opt==0)w=mp[{u,v}],upd(1,u,v,w),mp.erase({u,v});
		else read(w),mp[{u,v}]=w,upd(0,u,v,w);
		printf("%lld\n",getans());
	}
	return 0;
}