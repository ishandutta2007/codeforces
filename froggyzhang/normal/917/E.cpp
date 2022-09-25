#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,Q,ans[N];
string s[N];
vector<pair<int,char> > G[N];
class BIT{
	int b[N],n;
	inline int lowbit(int x){
		return x&(-x);
	}
public:
	void init(int _n){
		memset(b,0,sizeof(b));
		n=_n;
	}
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
};
int top[N],f[N],son[N],siz[N],dep[N],id[N],dfn[N],num;
char _c[N];
class Trie{
	int cnt;
	struct node{
		int ch[26],nxt;
	}t[N];
	BIT B;
	int dfn[N],num,siz[N],pos[N];
	vector<int> H[N];
	void init(int u){
		dfn[u]=++num;
		siz[u]=1;
		for(auto v:H[u]){
			init(v);
			siz[u]+=siz[v];
		}	
	}
public:
	Trie(){cnt=1;}
	vector<pair<int,int> > c[N];
	void Insert(const string &s,int id){
		int u=1;
		for(int i=0;i<(int)s.length();++i){
			int c=s[i]-'a';
			if(!t[u].ch[c]){
				t[u].ch[c]=++cnt;
			}
			u=t[u].ch[c];
		}
		pos[id]=u;
	}
	void build(){
		queue<int> q;
		for(int i=0;i<26;++i){
			t[0].ch[i]=1;
		}
		q.push(1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int c=0;c<26;++c){
				int v=t[u].ch[c];
				if(v){
					t[v].nxt=t[t[u].nxt].ch[c];
					q.push(v);
				}
				else{
					t[u].ch[c]=t[t[u].nxt].ch[c];
				}
			}
		}
		for(int i=2;i<=cnt;++i){
			H[t[i].nxt].push_back(i);	
		}
		init(1);
	}
	void dfs(int u,int fa,int o){
		B.Add(dfn[o],1);
		for(auto [id,k]:c[u]){
			int z=pos[abs(k)];
			ans[id]+=(k>0?1:-1)*(B.Ask(dfn[z]+siz[z]-1)-B.Ask(dfn[z]-1));
		}
		for(auto [v,c]:G[u]){
			if(v==f[u])continue;
			dfs(v,u,t[o].ch[c-'a']);
		}
		B.Add(dfn[o],-1);
	}
	void Run(){
		B.init(cnt);
		dfs(1,0,1);
	}
}T[2];
class KMP{
public:
	int len;
	vector<int> nxt,f,cha,ff[19];
	void init(const string &s){
		len=s.length();
		nxt.resize(len);
		f.resize(len);
		cha.resize(len);
		nxt[0]=-1,cha[0]=1,f[0]=-1;
		for(int i=1,j=-1;i<len;++i){
			while(~j&&s[j+1]^s[i])j=nxt[j];
			j+=s[j+1]==s[i];
			nxt[i]=j;
			if(i-j==cha[j]){
				cha[i]=cha[j],f[i]=f[j];
			}
			else{
				cha[i]=i-j,f[i]=j;	
			}
		}
		for(int i=0;i<=18;++i){
			ff[i].resize(len);
		}
		for(int i=0;i<len;++i){
			ff[0][i]=nxt[i];
		}
		for(int j=1;j<=18;++j){
			for(int i=0;i<len;++i){
				ff[j][i]=~ff[j-1][i]?ff[j-1][ff[j-1][i]]:-1;		
			}
		}
	}
	int Get(int u,int lim){
		if(u<lim)return u;
		for(int i=18;i>=0;--i){
			if(ff[i][u]>=lim)u=ff[i][u];	
		}
		return nxt[u];
	}
}K[N][2];
void exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
inline int calc(int a,int b,int c,int la,int lb){
	int x,y;
	int g=__gcd(a,b);
	if(c%g)return 0;
	c/=g,a/=g,b/=g;
	exgcd(a,b,x,y);
	x=(1LL*x*c%b+b)%b;
	y=(c-a*x)/b;
	if(y<0)return 0;
	if(y>lb){
		int t=(y-lb-1)/a+1;
		y-=t*a,x+=t*b;	
	}
	if(x>la||x<0||y>lb||y<0)return 0;
	return min((la-x)/b+1,y/a+1);
}
void Solve(int u,int L,int R,int id){
	int _L=L,_R=R;
	for(L=_L;L>=0;L=K[u][0].f[L]){
		for(R=_R;R>=0;R=K[u][1].f[R]){
			int c=(int)s[u].length()-(K[u][1].f[R]+K[u][1].cha[R])-(K[u][0].f[L]+K[u][0].cha[L])-2;
			if(c>=0){
				ans[id]+=calc(K[u][0].cha[L],K[u][1].cha[R],c,(L-K[u][0].f[L])/K[u][0].cha[L]-1,(R-K[u][1].f[R])/K[u][1].cha[R]-1);
			}
		}
	}	
}
void dfs1(int u){
	siz[u]=1;
	dep[u]=dep[f[u]]+1;
	for(auto [v,c]:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		_c[v]=c;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}	
}
void dfs2(int u,int topf){
	top[u]=topf;
	dfn[u]=++num;
	id[num]=u;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto [v,c]:G[u]){
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
struct Query{
	int x,y,k,lca;
}q[N];
int Jump(int u,int t){
	while(dep[u]-dep[top[u]]<t){
		t-=dep[u]-dep[f[top[u]]];
		u=f[top[u]];
	}
	return id[dfn[u]-t];
}
class SA{
public:
	vector<int> rk,sa,tp;
	int len;
	void Qsort(){
		int C=max(26,len);
		vector<int> cnt(C);
		for(int i=0;i<len;++i)++cnt[rk[i]];
		for(int i=1;i<C;++i)cnt[i]+=cnt[i-1];
		for(int i=len-1;i>=0;--i)sa[--cnt[rk[tp[i]]]]=tp[i];
	}
	void init(const string &s){
		len=s.length();
		rk.resize(len),sa.resize(len),tp.resize(len);
		for(int i=0;i<len;++i)rk[i]=s[i]-'a',tp[i]=i;
		Qsort();
		for(int w=1;w<=len;w<<=1){
			int now=0;
			for(int i=len-w;i<len;++i)tp[now++]=i;
			for(int i=0;i<len;++i)if(sa[i]>=w)tp[now++]=sa[i]-w;
			Qsort();
			swap(rk,tp);
			rk[sa[0]]=now=0;
			for(int i=1;i<len;++i){
				rk[sa[i]]=sa[i]+w<len&&sa[i-1]+w<len&&tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w]?now:++now;
			}
			if(now==len-1)break;
		}
	}
}S[N][2];
template<int mod,int base>
class Hasher{
public:
	int len;
	vector<int> h,pw;
	string s;
	void init_pw(){
		pw.resize(len+1);
		pw[0]=1;
		for(int i=1;i<=len;++i){
			pw[i]=1LL*pw[i-1]*base%mod;
		}
	}
	void init1(const string &_s){
		s=_s;
		len=s.length();
		h.resize(len);
		init_pw();
		h[0]=s[0];
		for(int i=1;i<len;++i){
			h[i]=(1LL*h[i-1]*base+s[i])%mod;
		}	
	}
	void dfs3(int u){
		for(auto [v,c]:G[u]){
			if(v==f[u])continue;
			h[v]=(1LL*h[u]*base+c)%mod;
			dfs3(v);
		}	
	}
	void init2(int n){
		len=n+1;
		h.resize(len);
		init_pw();
		dfs3(1);
	}
	int Ask1(int l,int r)const{
		return (h[r]+(!l?0:1LL*(mod-h[l-1])*pw[r-l+1]))%mod;
	}
	int Ask2(int l,int r)const{
		return (h[r]+1LL*(mod-h[l])*pw[dep[r]-dep[l]])%mod;
	}
};
using Hash=Hasher<998244353,233>;
Hash H[N][2],Y;
pair<int,int> Cmp(int u,int lca,const Hash &H,int z){
	int l=1,r=min(dep[u]-dep[lca]+1,H.len-z+1),ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(Y.Ask2(lca,Jump(u,dep[u]-dep[lca]-mid))==H.Ask1(z,z+mid-1)){
			ans=mid,l=mid+1;		
		}
		else{
			r=mid;
		}
	}
	char c1=ans==dep[u]-dep[lca]?0:_c[Jump(u,dep[u]-dep[lca]-ans-1)];
	char c2=ans==H.len-z?0:H.s[z+ans];
	return make_pair(ans,c1>=c2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>Q;
	for(int i=1;i<n;++i){
		int u,v;
		char c;
		cin>>u>>v>>c;
		G[u].emplace_back(v,c);
		G[v].emplace_back(u,c);
	}
	dfs1(1);
	dfs2(1,1);
	for(int i=1;i<=m;++i){
		cin>>s[i];
		T[0].Insert(s[i],i);
		T[1].Insert(string(s[i].rbegin(),s[i].rend()),i);
		K[i][0].init(s[i]);
		K[i][1].init(string(s[i].rbegin(),s[i].rend()));
		S[i][0].init(s[i]);
		S[i][1].init(string(s[i].rbegin(),s[i].rend()));
		H[i][0].init1(s[i]);
		H[i][1].init1(string(s[i].rbegin(),s[i].rend()));
	}
	Y.init2(n);
	T[0].build();
	T[1].build();
	for(int i=1;i<=Q;++i){
		cin>>q[i].x>>q[i].y>>q[i].k;
		int lca;
		lca=q[i].lca=LCA(q[i].x,q[i].y);
		if(dep[q[i].y]-dep[lca]>=s[q[i].k].length()){
			T[0].c[q[i].y].emplace_back(i,q[i].k);
			T[0].c[Jump(q[i].y,dep[q[i].y]-dep[lca]-(int)s[q[i].k].length()+1)].emplace_back(i,-q[i].k);
		}
		if(dep[q[i].x]-dep[lca]>=s[q[i].k].length()){
			T[1].c[q[i].x].emplace_back(i,q[i].k);
			T[1].c[Jump(q[i].x,dep[q[i].x]-dep[lca]-(int)s[q[i].k].length()+1)].emplace_back(i,-q[i].k);
		}
		int Len=s[q[i].k].length();
		auto Getl=[&]()->int{
			int l=0,r=Len,pos=0,Lcp=0;
			while(l<r){
				int mid=(l+r)>>1;
				auto [lcp,o]=Cmp(q[i].x,q[i].lca,H[q[i].k][1],S[q[i].k][1].sa[mid]);
				if(o){
					pos=mid,l=mid+1;
					Lcp=lcp;
				}
				else{
					r=mid;
				}
			}
			if(pos<(int)s[q[i].k].length()-1){
				auto [lcp,o]=Cmp(q[i].x,q[i].lca,H[q[i].k][1],S[q[i].k][1].sa[pos+1]);
				if(lcp>Lcp)Lcp=lcp,++pos;
			}
			Lcp=min(Lcp,Len-1);
			return Lcp>0?K[q[i].k][0].Get(Len-1-S[q[i].k][1].sa[pos],Lcp):-1;
		};
		auto Getr=[&]()->int{
			int l=0,r=Len,pos=-1,Lcp=0;
			while(l<r){
				int mid=(l+r)>>1;
				auto [lcp,o]=Cmp(q[i].y,q[i].lca,H[q[i].k][0],S[q[i].k][0].sa[mid]);
				if(o){
					pos=mid,l=mid+1;
					Lcp=lcp;
				}
				else{
					r=mid;
				}
			}
			if(pos<Len-1){
				auto [lcp,o]=Cmp(q[i].y,q[i].lca,H[q[i].k][0],S[q[i].k][0].sa[pos+1]);
				if(lcp>Lcp)Lcp=lcp,++pos;
			}
			Lcp=min(Lcp,Len-1);
			return Lcp>0?K[q[i].k][1].Get(Len-1-S[q[i].k][0].sa[pos],Lcp):-1;
		};
		int posl=Getl();
		int posr=Getr();
		if(~posl&&~posr)Solve(q[i].k,posl,posr,i);
	}
	T[0].Run();
	T[1].Run();
	for(int i=1;i<=Q;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}