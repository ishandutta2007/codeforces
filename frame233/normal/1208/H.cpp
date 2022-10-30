#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,inf=0x3f3f3f3f;
std::vector<int> e[N];
struct DS{
	std::map<int,int> mp;
	int f,all,cur;
	inline int get(int x){auto it=mp.find(x);return it==mp.end()?0:it->second;}
	inline void fix(){
		while((cur-get(f))*2-all>=f+1)cur-=get(f++);
		while(cur*2-all<f)cur+=get(--f);
	}
	inline void ins(int x){cur+=x>=f,++all,++mp[x],fix();}
	inline void del(int x){
		cur-=x>=f,--all;
		if(auto it=mp.find(x);!--it->second)mp.erase(it);
		fix();
	}
}s[N];
int Fa[N],dep[N],siz[N],son[N],top[N],ed[N],dfn[N],rev[N],id,a[N],dp[N],n;
struct node{int a,b;}f[N<<2],val[N];
inline node merge(const node &x,const node &y){return x.a<-inf?y:y.a<-inf?x:(node){std::max(std::min(y.a,x.b),x.a),std::max(std::min(y.b,x.b),x.a)};}
int M;void build(int n){for(M=1;M<=n+2;M<<=1);for(int i=1;i<=n;++i)f[i+M]=val[rev[i]];for(int i=M-1;i>=1;--i)f[i]=merge(f[i<<1],f[i<<1|1]);}
void upd(int x,const node &C){f[x+=M]=C;for(x>>=1;x;x>>=1)f[x]=merge(f[x<<1],f[x<<1|1]);}
node ask(int s,int t){
	node A={-inf-1,-inf-1},B={-inf-1,-inf-1};
	for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1){
		if(~s&1)A=merge(A,f[s^1]);
		if(t&1)B=merge(f[t^1],B);
	}
	return merge(A,B);
}
inline node get(int x){
	if(~a[x])return a[x]?(node){inf,inf}:(node){-inf,-inf};
	int A,B;
	s[x].ins(-inf),A=s[x].f,s[x].del(-inf);
	s[x].ins(inf),B=s[x].f,s[x].del(inf);
	return {A,B};
}
void dfs1(int x,int fa){
	if(~a[x])dp[x]=a[x]?inf:-inf;
	Fa[x]=fa,dep[x]=dep[fa]+1,siz[x]=1;
	for(auto v:e[x])if(v!=fa){
		dfs1(v,x),siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
	for(auto v:e[x])if(v!=fa&&v!=son[x])s[x].ins(dp[v]);
	if(son[x])s[x].ins(dp[son[x]]),dp[x]=s[x].f,s[x].del(dp[son[x]]);
	val[x]=get(x);
}
void dfs2(int x,int topf){
	top[x]=topf,dfn[x]=++id,rev[id]=x,ed[topf]=x;
	if(son[x])dfs2(son[x],topf);
	for(auto v:e[x])if(!top[v])dfs2(v,v);
}
inline int calc(int x){return ask(dfn[x],dfn[ed[top[x]]]).a;}
int main(){
	int k;read(n,k);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	for(int i=1;i<=n;++i)read(a[i]);
	dfs1(1,0),dfs2(1,1),build(n);
	int q,opt,x,y;read(q);
	while(q--){
		read(opt);
		if(opt==1)read(x),printf("%d\n",k<=calc(x));
		else if(opt==2){
			read(x,y),a[x]=y;int last=x;
			while(top[x]>1){
				x=top[x],s[Fa[x]].del(calc(x)),upd(dfn[last],get(last)),s[Fa[x]].ins(calc(x));
				last=Fa[x],x=Fa[x];
			}
			upd(dfn[last],get(last));
		}
		else read(k);
	}
	return 0;
}