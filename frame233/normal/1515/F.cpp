#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300005;
typedef long long ll;
typedef std::pair<int,int> pi;
ll a[N];
std::vector<pi> e[N];
struct node{
	int u;ll d;
	inline bool operator < (const node &o)const{return d==o.d?u<o.u:d<o.d;}
	inline bool operator == (const node &o)const{return u==o.u&&d==o.d;}
};
template<typename _Tp>
class heap{
public:
	std::priority_queue<_Tp> q1,q2;
	int siz;
	inline bool empty(){return !siz;}
	inline int size(){return siz;}
	inline void push(const _Tp &o){q1.push(o);++siz;}
	inline void pop(const _Tp &o){q2.push(o);--siz;}
	inline _Tp top(){
		while(!q2.empty()&&q1.top()==q2.top()) q1.pop(),q2.pop();
		return q1.top();
	}
};
heap<node> q;
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	int n,m,X;read(n,m,X);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,x,y;i<=m;++i)read(x,y),e[x].pb({y,i}),e[y].pb({x,i});
	for(int i=1;i<=n;++i)q.push({i,a[i]}),fa[i]=i;
	std::vector<int> ans;
	while(SZ(q)>1){
		node x=q.top();q.pop(x);
		while(true){
			assert(!e[x.u].empty());
			pi E=e[x.u].back();e[x.u].pop_back();
			int u=x.u,v=find(E.first);
			if(u==v)continue;
			if(a[u]+a[v]<X)return puts("NO"),0;
			q.pop({v,a[v]});
			if(SZ(e[u])>SZ(e[v]))std::swap(u,v);
			ans.pb(E.second),fa[u]=v,a[v]+=a[u]-X,q.push({v,a[v]});
			for(auto it:e[u])e[v].emplace_back(it);
			std::vector<pi>().swap(e[u]);
			break;
		}
	}
	printf("YES\n");
	for(auto it:ans)printf("%d\n",it);
	return 0;
}