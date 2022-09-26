#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define N 200020
typedef long long ll;
const double inf=1e18;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,t,Q;
int p[N],l[N],c[N];
double ans;
inline double calc(int u,int c){
	if(c==-1)return inf;
	if(c>=l[u])return 0;
	return 1.0*p[u]*l[u]/(1.0*(c+1+l[u])*(c+l[u]));
}
inline double get(int u){
	return p[u]*1.0*min(c[u],l[u])/(min(c[u],l[u])+l[u]);
}
struct Tick{
	double val;
	int u,c;
	Tick(int _u,int _c){u=_u,c=_c,val=calc(u,c);}
	bool operator <(const Tick b)const{
		return val==b.val?u<b.u:val<b.val;
	}
};
set<Tick> s,d;
inline void Insert(){
	Tick tmp=*--s.end();
	int u=tmp.u;
	ans+=tmp.val;
	s.erase(tmp);d.erase(Tick(u,c[u]-1));
	++c[u];
	s.insert(Tick(u,c[u]));d.insert(tmp);
}
inline void Del(){
	Tick tmp=*d.begin();
	int u=tmp.u;
	ans-=tmp.val;
	s.erase(Tick(u,c[u]));d.erase(tmp);
	--c[u];
	s.insert(tmp);d.insert(Tick(u,c[u]-1));
}
int main(){
	n=read(),t=read(),Q=read();
	for(int i=1;i<=n;++i){
		p[i]=read();
	}
	for(int i=1;i<=n;++i){
		l[i]=read();
		s.insert(Tick(i,0));
		d.insert(Tick(i,-1));
	}
	while(t--)Insert();
	while(Q--){
		int opt=read(),u=read();
		s.erase(Tick(u,c[u])),d.erase(Tick(u,c[u]-1)),ans-=get(u);
		l[u]+=(opt==1?1:-1);
		s.insert(Tick(u,c[u])),d.insert(Tick(u,c[u]-1)),ans+=get(u);
		while((--s.end())->val>d.begin()->val)Del(),Insert();
		printf("%.10lf\n",ans);
	}
	return 0;
}