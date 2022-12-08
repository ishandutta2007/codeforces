#include<bits/stdc++.h>
using namespace std;
#define enter pc('\n')
#define space pc(' ')
typedef long long ll;
const int MAXL=1<<22;
char i_str[MAXL],o_str[MAXL],*i_s,*i_t;
int o_t;
inline char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
inline void gs(char *s) {
	*s=gc();
	while(*s==' '||*s=='\n')*s=gc();
	while(*s!=' '&&*s!='\n')*++s=gc();
	*s='\0';
}
inline int read() {
	int x=0,f=0;
	char ch=gc();
	for(; ch<'0'||ch>'9'; ch=gc())
		if(ch=='-')f=1;
	for(; ch>='0'&&ch<='9'; ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
#define fl fwrite(o_str,1,o_t,stdout),o_t=0
inline void pc(char x) {
	o_str[o_t++]=x;
	if(o_t==MAXL)fl;
}
inline void write(ll x) {
	if(x<0)x=-x,pc('-');
	if(x>9)write(x/10);
	pc(x%10^48);
}
const int N=5e5+10,mod=998244353,B=13331;
#define fa(x) fa[x][0]
vector<int>S[N];
int D[N],dep[N],dfn[N],Log[N],pos[N],jp[N],top[N],fa[N][22],son[N];
int a,b,c,d,pa,pb,len1,len2,dfns;
int has1[N],has2[N],inv[N],Pow[N];
char s[N];
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
void pre(int x) {
	has2[x]=(1ll*has2[fa(x)]*B+s[x])%mod;
	has1[x]=(has1[fa(x)]+1ll*s[x]*Pow[D[fa(x)]])%mod;
	D[x]=D[fa(x)]+1;
	for(int i=1;i<20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int y:S[x]) {
		if(y==fa(x))continue;
		fa(y)=x;
		pre(y);
		if(dep[y]+1>dep[x])
			dep[x]=dep[son[x]=y]+1;
	}
}
void dfs(int x) {
	if(son[fa(x)]==x)top[x]=top[fa(x)];
	else top[x]=x;
	pos[dfn[x]=++dfns]=x;
	if(son[x])dfs(son[x]);
	for(int y:S[x]) {
		if(y==fa(x)||y==son[x])continue;
		dfs(y);
		jp[dfn[y]]=x;
		for(int i=1;i<=dep[y];i++)
			jp[dfn[y]+i]=fa(jp[dfn[y]+i-1]);
	}
}
int calc(int x,int k) {
	return jp[dfn[x]+k-1];
}
int get(int x,int k) {
	if(k==0)return x;
	x=fa[x][Log[k]];
	k-=1<<Log[k];
	if(D[x]-D[top[x]]<k)return calc(top[x],-D[x]+k+D[top[x]]);
	else return pos[dfn[x]-k];
}
int lca(int a,int b) {
	if(D[a]<D[b])swap(a,b);
	for(int i=19;i>=0;i--)
		if(D[fa[a][i]]>=D[b])
			a=fa[a][i];
	if(a==b)return a;
	for(int i=19;i>=0;i--)
		if(fa[a][i]!=fa[b][i]) {
			a=fa[a][i];
			b=fa[b][i];
		}
	return fa(a);
}
int get(int a,int b,int p) {
	if(p==-1)p=b;
	int H1=1ll*(has1[a]-has1[fa(p)]+mod)*inv[D[p]-1]%mod;
	int H2=(has2[b]-1ll*has2[p]*Pow[D[b]-D[p]]%mod+mod)%mod;
	return (1ll*H1*Pow[D[b]-D[p]]+H2)%mod;
}
int check(int k) {
	int h1=0,h2=0;
	if(D[a]-D[pa]+1>=k)h1=get(a,get(a,k-1),-1);
	else h1=get(a,get(b,len1-k),pa);
	if(D[c]-D[pb]+1>=k)h2=get(c,get(c,k-1),-1);
	else h2=get(c,get(d,len2-k),pb);
	return h1==h2;
}
int main() {
	int n,q;
	n=read();
	gs(s+1);
	Pow[0]=inv[0]=1;
	Pow[1]=B;inv[1]=qpow(B,mod-2);
	for(int i=1;i<n;i++) {
		Pow[i+1]=1ll*Pow[i]*B%mod;
		inv[i+1]=1ll*inv[i]*inv[1]%mod;
		a=read(),b=read();
		S[a].push_back(b);
		S[b].push_back(a);
	}
	Log[1]=0;
	for(int i=2;i<=n;i++)
		Log[i]=Log[i/2]+1;
	pre(1);
	dfs(1);
	q=read();
	while(q--) {
		a=read(),b=read(),c=read(),d=read();
		pa=lca(a,b),pb=lca(c,d);
		len1=D[a]+D[b]-2*D[pa]+1,len2=D[c]+D[d]-2*D[pb]+1;
		int l=1,r=min(len1,len2);
		while(l<=r) {
			int mid=(l+r)>>1;
			if(check(mid))l=mid+1;
			else r=mid-1;
		}
		write(l-1),enter;
	}
	fl;
	return 0;
}