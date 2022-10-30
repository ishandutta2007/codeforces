#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,M=N<<1,mod=1000526981,base=2333;typedef std::pair<int,int> pi;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int ans[N],sa[M],rk[M],tax[M],tp[M],s[M],a[M],dp[M],p;char t[N];std::vector<pi> e[N];
void Rsort(int n,int m){
	memset(tax,0,(m+3)<<2);
	for(int i=1;i<=n;++i)++tax[rk[i]];
	for(int i=1;i<=m;++i)tax[i]+=tax[i-1];
	for(int i=n;i>=1;--i)sa[tax[rk[tp[i]]]--]=tp[i];
}
void SA(int n,int m){
	for(int i=1;i<=n;++i)rk[i]=s[i],tp[i]=i;
	Rsort(n,m);
	for(int w=1,p=0;p<n;w<<=1,m=p){
		p=0;for(int i=0;i<w;++i)tp[++p]=n-i;
		for(int i=1;i<=n;++i)if(sa[i]>w)tp[++p]=sa[i]-w;
		Rsort(n,m),memcpy(tp,rk,(n+3)<<2),rk[sa[1]]=p=1;
		for(int i=2;i<=n;++i)rk[sa[i]]=tp[sa[i-1]]==tp[sa[i]]&&tp[sa[i-1]+w]==tp[sa[i]+w]?p:++p;
	}
}
int anc[N][18],f[N][18],g[N][18],pw[N],dep[N],ipw[N];
void dfs(int x,int fa){
	for(int i=1;i<18&&anc[x][i-1];++i){
		anc[x][i]=anc[anc[x][i-1]][i-1];
		f[x][i]=(1LL*pw[1<<(i-1)]*f[x][i-1]+f[anc[x][i-1]][i-1])%mod;
		g[x][i]=(g[x][i-1]+1LL*pw[1<<(i-1)]*g[anc[x][i-1]][i-1])%mod;
	}
	for(auto [v,w]:e[x])if(v!=fa)anc[v][0]=x,f[v][0]=w,g[v][0]=w,dep[v]=dep[x]+1,dfs(v,x);
}
int lca(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=17;i>=0;--i)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
	if(x==y)return x;
	for(int i=17;i>=0;--i)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
int jump(int x,int k){for(int i=17;i>=0;--i)if(k>>i&1)x=anc[x][i];return x;}
int getf(int x,int k){int ans=0;for(int i=17;i>=0;--i)if(k>>i&1)ans=(1LL*ans*pw[1<<i]+f[x][i])%mod,x=anc[x][i];return ans;}
int getg(int x,int k){int ans=0,coef=1;for(int i=17;i>=0;--i)if(k>>i&1)ans=(1LL*coef*g[x][i]+ans)%mod,coef=1LL*coef*pw[1<<i]%mod,x=anc[x][i];return ans;}
int x,y,z,d;
int lcp(int pos){
	int x=::x,y=::y,z=::z;
	int len=std::min(dep[x]-dep[z],p-pos+1);
	if((dp[pos+len-1]+1LL*(mod-dp[pos-1])*pw[len])%mod==getf(x,len)){
		pos+=len,len=std::min(dep[y]-dep[z],p-pos+1);
		y=jump(y,dep[y]-dep[z]-len);int cur=getg(y,len),rest=len;
		if((dp[pos+len-1]+1LL*(mod-dp[pos-1])*pw[len])%mod==cur)return d;
		for(int i=17;i>=0;--i)if((1<<i)<=rest){
			int tmp=1LL*(cur-g[y][i]+mod)*ipw[1<<i]%mod,LEN=rest-(1<<i);
			if(tmp!=(dp[pos+LEN-1]+1LL*(mod-dp[pos-1])*pw[LEN])%mod)cur=tmp,rest=LEN,y=anc[y][i];
		}
		return dep[x]-dep[z]+rest-1;
	}
	else{
		int cur=0,cl=0;
		for(int i=17;i>=0;--i)if(cl+(1<<i)<=len){
			int tmp=(1LL*cur*pw[1<<i]+f[x][i])%mod,LEN=cl+(1<<i);
			if(tmp==(dp[pos+LEN-1]+1LL*(mod-dp[pos-1])*pw[LEN])%mod)cur=tmp,cl=LEN,x=anc[x][i];
		}
		return cl;
	}
}
int cmp(int pos){
	int len=lcp(pos);if(len==d)return 1;
	int A=len+1<=dep[x]-dep[z]?f[jump(x,len)][0]:f[jump(y,d-len-1)][0],B=s[pos+len];
	return A<B;
}
bool check(int pos){
	if(p-pos+1<d)return 0;
	int len=dep[x]-dep[z];
	if((dp[pos+len-1]+1LL*(mod-dp[pos-1])*pw[len])%mod==getf(x,len)){
		pos+=len,len=dep[y]-dep[z];
		if((dp[pos+len-1]+1LL*(mod-dp[pos-1])*pw[len])%mod==getg(y,len))return 1;
	}
	return 0;
}
int c[N];void add(int x,int C){++x;for(;x<N;x+=lowbit(x))c[x]+=C;}
int ask(int x){++x;int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
struct qry{int l,r,id,opt;};std::vector<qry> Q[M];
int main(){
	pw[0]=1;for(int i=1;i<N;++i)pw[i]=1LL*base*pw[i-1]%mod;
	ll inv=ksm(base);ipw[0]=1;for(int i=1;i<N;++i)ipw[i]=1LL*inv*ipw[i-1]%mod;
	int n,m,q;read(n,m,q);char ch;
	for(int i=1,x,y;i<n;++i){
		read(x,y);do{ch=getchar();}while(!isalpha(ch));
		e[x].pb({y,ch}),e[y].pb({x,ch});
	}
	for(int i=1;i<=m;++i){
		scanf("%s",t+1);int len=strlen(t+1);
		for(int j=1;j<=len;++j)s[++p]=t[j],a[p]=i;
		s[++p]=i+127,a[p]=0;
	}
	for(int i=1;i<=p;++i)dp[i]=(1LL*dp[i-1]*base+s[i])%mod;
	SA(p,128+m);dep[1]=1,dfs(1,0);int L,R;
	for(int i=1;i<=q;++i){
		read(x,y,L,R),z=lca(x,y),d=dep[x]+dep[y]-dep[z]*2;
		int l=1,r=p,mid;while(l<r)mid=(l+r)>>1,cmp(sa[mid])?r=mid:l=mid+1;
		int fir=l;l=fir-1,r=p;while(l<r)mid=(l+r+1)>>1,check(sa[mid])?l=mid:r=mid-1;
		Q[l].pb({L,R,i,1}),Q[fir-1].pb({L,R,i,-1});
	}
	for(int i=1;i<=p;++i){
		add(a[sa[i]],1);
		for(auto [l,r,id,opt]:Q[i])ans[id]+=opt*(ask(r)-ask(l-1));
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}