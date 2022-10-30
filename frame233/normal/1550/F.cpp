#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
typedef std::pair<int,int> pi;
int a[N],dis[N];
struct node{
	int x,d;
	inline bool operator < (const node &o)const{return d>o.d;}
};
std::priority_queue<node> q;
inline void upd(int x,int C){if(dis[x]>C)dis[x]=C,q.push({x,C});}
int main(){
	int n,Q,_,__;read(n,Q,_,__);
	std::set<pi> s;for(int i=1;i<=n;++i)read(a[i]),s.insert({a[i],i});
	memset(dis,63,sizeof(dis)),q.push({_,0}),dis[_]=0;
	while(!q.empty()){
		auto [x,d]=q.top();q.pop();if(d!=dis[x])continue;
		if(auto it=s.find({a[x],x});it!=s.end())s.erase(it);
		for(auto to:{a[x]-__,a[x]+__}){
			int l=to-d,r=to+d;
			auto itl=s.lower_bound({l,0}),itr=s.upper_bound({r,n});
			if(auto it=itl;it!=s.begin())--it,upd(it->second,d+l-it->first);
			if(auto it=itr;it!=s.end())upd(it->second,d+it->first-r);
			for(auto it=itl;it!=itr;++it)upd(it->second,d);
			s.erase(itl,itr);
		}
		if(x!=_&&x>1)upd(x-1,d+a[x]-a[x-1]);
		if(x!=_&&x<n)upd(x+1,d+a[x+1]-a[x]);
	}
	while(Q--){
		int x,y;read(x,y);
		puts(y>=dis[x]?"Yes":"No");
	}
	return 0;
}