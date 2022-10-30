#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=400005,inf=0x3f3f3f3f;
std::vector<int> e[N];
int dep[N],f[N][20],siz[N],dfn[N],id,pos,fir[N],Log2[N],anc[N][20],rev[N],Fa[N];
inline int _min(int x,int y){return dep[x]<dep[y]?x:y;}
void dfs(int x,int fa){
	anc[x][0]=fa;for(int i=1;i<20;++i)anc[x][i]=anc[anc[x][i-1]][i-1];
	dfn[x]=++id,siz[x]=1,dep[x]=dep[fa]+1,f[++pos][0]=x,fir[x]=pos,rev[id]=x,Fa[x]=fa;
	for(auto v:e[x])if(v!=fa)dfs(v,x),f[++pos][0]=x,siz[x]+=siz[v];
}
inline int lca(int l,int r){
	l=fir[l],r=fir[r];if(l>r)std::swap(l,r);
	int k=Log2[r-l+1];
	return _min(f[l][k],f[r-(1<<k)+1][k]);
}
inline int getdis(int x,int y){return !x||!y?(!x&&!y?-inf-1:-inf):dep[x]+dep[y]-2*dep[lca(x,y)];}
struct diam{
	int x,y,len;
	diam(){x=0,y=0,len=-inf;}
	diam(int X,int Y){x=X,y=Y,len=getdis(x,y);}
	inline bool operator < (const diam &o)const{return len<o.len;}
}T[N<<1];
inline diam merge(const diam &a,const diam &b){return std::max({a,b,diam(a.x,b.x),diam(a.x,b.y),diam(a.y,b.x),diam(a.y,b.y)});}
int M,cnt[N];
void build(int n){for(M=1;M<=n+2;M<<=1);}
void upd(int x,int C){
	cnt[x]+=C,T[x+M]=cnt[x]?diam(rev[x],rev[x]):diam();
	for(x=(x+M)>>1;x;x>>=1)T[x]=merge(T[x<<1],T[x<<1|1]);
}
diam ask(int s,int t){
	diam ans=diam(0,0);
	for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1){
		if(~s&1)ans=merge(ans,T[s^1]);
		if(t&1)ans=merge(ans,T[t^1]);
	}
	return ans;
}
int c[N];
void ADD(int x,int C){for(;x<N;x+=lowbit(x))c[x]+=C;}
int ASK(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
struct comp{inline bool operator () (int a,int b)const{return dep[a]==dep[b]?a>b:dep[a]>dep[b];}};
std::multiset<int,comp> S;
inline int jump(int x,int k){for(int i=19;i>=0;--i)if(k>>i&1)x=anc[x][i];return std::max(x,1);}
int main(){
	for(int i=2;i<N;++i)Log2[i]=Log2[i>>1]+1;
	int n,q;read(n,q);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	dfs(1,0);for(int i=pos;i>=1;--i)for(int j=1;j<20&&i+(1<<(j-1))<=pos;++j)f[i][j]=_min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	build(n);int opt,x,y,z,d,cur=0;
	while(q--){
		read(opt);
		if(opt<=2){
			int C=opt==1?1:-1;read(x,y),z=lca(x,y);
			upd(dfn[z],C),ADD(dfn[x],C),ADD(dfn[y],C),ADD(dfn[z],-C),cur+=C;
			if(opt==1)S.insert(z);else S.erase(S.find(z));
		}
		else{
			read(d);int x=jump(*S.begin(),d),y=jump(x,d);
			if(ASK(dfn[y]+siz[y]-1)-ASK(dfn[y]-1)!=cur){puts("No");continue;}
			diam D=ask(dfn[y],dfn[y]+siz[y]-1);
			if(getdis(x,D.x)>d||getdis(x,D.y)>d){puts("No");continue;}
			else puts("Yes");
		}
	}
	return 0;
}