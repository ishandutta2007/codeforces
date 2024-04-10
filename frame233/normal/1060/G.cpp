#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef long long ll;typedef unsigned int uint;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
ll ans[N];int a[N],ls[N],rs[N];ll mn[N],val[N],pos[N],tag1[N],tag2[N],step;uint key[N];
inline void pushup(int u){mn[u]=std::min({mn[ls[u]],mn[rs[u]],val[u]});}
inline void upd1(int u,int C){if(u)val[u]+=C,mn[u]+=C,tag1[u]+=C;}
inline void upd2(int u,int C){if(u)pos[u]+=C,tag2[u]+=C;}
inline void pushdown(int u){
	if(tag1[u])upd1(ls[u],tag1[u]),upd1(rs[u],tag1[u]),tag1[u]=0;
	if(tag2[u])upd2(ls[u],tag2[u]),upd2(rs[u],tag2[u]),tag2[u]=0;
}
void split(int &x,int &y,int u,int v){
	if(!u)return x=0,y=0,void();
	pushdown(u);
	if(pos[u]<=v)x=u,split(rs[x],y,rs[u],v);
	else y=u,split(x,ls[y],ls[u],v);
	pushup(u);
}
int merge(int a,int b){
	if(!a||!b)return a|b;
	pushdown(a),pushdown(b);
	if(key[a]<key[b])return rs[a]=merge(rs[a],b),pushup(a),a;
	else return ls[b]=merge(a,ls[b]),pushup(b),b;
}
void get(int &u,int tar){
	if(!u||mn[u]>tar)return;
	pushdown(u),get(ls[u],tar),get(rs[u],tar);
	if(val[u]<=tar)ans[u]=pos[u]+val[u]*step,u=merge(ls[u],rs[u]);
	else pushup(u);
}
void out(int u){
	if(!u)return;
	pushdown(u),ans[u]=pos[u]+1LL*val[u]*step;
	out(ls[u]),out(rs[u]);
}
struct node{int x,k,id;};std::vector<node> vec[N];
void apply(int &u,int t,int k){get(u,t),upd1(u,-t),upd2(u,t*k);}
int main(){
	mn[0]=1e9;int n,m;read(n,m);
	for(int i=1;i<=n;++i)read(a[i]),a[i]-=i;
	for(int t=1,x,k;t<=m;++t){
		read(x,k);if(x<=a[1]){ans[t]=x;continue;}else if(x>a[n]){ans[t]=x+1LL*k*n;continue;}
		vec[std::lower_bound(a+1,a+n+1,x)-a-1].pb({x,k,t});
	}
	int rt=0;
	for(int i=1;i<n;++i){
		step=i;int tmp=(a[i+1]-a[i]-1)/i,lim=a[i+1]-i*tmp;
		int x,y;split(x,y,rt,lim),apply(x,tmp+1,i),apply(y,tmp,i),rt=merge(y,x);
		for(const auto &it:vec[i]){
			int t=it.id,tmp=(a[i+1]-it.x)/i+1;
			if(it.k<=tmp){ans[t]=it.x+it.k*i;continue;}
			key[t]=rnd(),val[t]=mn[t]=it.k-tmp,pos[t]=it.x+tmp*i;
			int x,y;split(x,y,rt,pos[t]),rt=merge(merge(x,t),y);
		}
	}
	step=n,out(rt);
	for(int i=1;i<=m;++i)printf("%lld\n",ans[i]);
	return 0;
}