#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define HEAP(...) priority_queue<__VA_ARGS__ >
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > > 
#define pii pair<int,int> 
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define SZ(x) ((int)x.size())
using namespace std;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
const int BufferSize=1<<16;
char buffer[BufferSize],*Bufferhead,*Buffertail;
bool Terminal;
inline char Getchar(){
	if(Bufferhead==Buffertail){
		int l=fread(buffer,1,BufferSize,stdin);
		if(!l){Terminal=1;return 0;}
		Buffertail=(Bufferhead=buffer)+l;
	}
	return *Bufferhead++;
}
template<class T>inline bool read(T &x){
	x=0;char c=Getchar(),rev=0;
	while(c<'0'||c>'9'){rev|=c=='-';c=Getchar();if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	if(c=='.'){
		c=Getchar();double t=0.1;
		while(c>='0'&&c<='9') x=x+(c-'0')*t,c=Getchar(),t=t/10;
	}
	x=rev?-x:x;
	return 1;
}
template<class T1,class T2> inline bool read(T1 &x,T2 &y){return read(x)&read(y);}
template<class T1,class T2,class T3> inline bool read(T1 &x,T2 &y,T3 &z){return read(x)&read(y)&read(z);}
template<class T1,class T2,class T3,class T4> inline bool read(T1 &x,T2 &y,T3 &z,T4 &w){return read(x)&read(y)&read(z)&read(w);}
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c='\n'){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
//--------------------------------head---------------------------------------------

const int inf=0x3f3f3f3f;
const int N=200005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m,k,a[N],l[N],r[N];
vi g[N],f[N],ins[N];
bool vis[N];

inline void predfs(int x,vi &seq){
	vis[x]=1;
	for(int y:f[x])
		if(!vis[y]) predfs(y,seq);
	seq.pb(x);
}
inline void predfs(int x){
	vis[x]=1;
	for(int y:g[x])
		if(!vis[y]) predfs(y);
}
bool check(){
	vi seq(0);
	for(int i=1;i<=n;i++)
		if(!vis[i]) predfs(i,seq);
	clr(vis,0);
	reverse(seq.begin(),seq.end());
	for(int i:seq)
		if(!vis[i]) predfs(i); else return 0;
	return 1;
}

inline void dfs(int x){
	vis[x]=1;l[x]=1;
	for(int y:g[x]){
		if(!vis[y]) dfs(y);
		gmax(l[x],l[y]+1);
	}
	if(a[x]){
		if(l[x]>a[x]){puts("-1");exit(0);}
		l[x]=a[x];
	}
}
inline void idfs(int x){
	vis[x]=1;r[x]=k;
	for(int y:f[x]){
		if(!vis[y]) idfs(y);
		gmin(r[x],r[y]-1);
	}
	if(a[x]){
		if(r[x]<a[x]){puts("-1");exit(0);}
		r[x]=a[x];
	}
}

inline void upt(int x,int p){
//	dprintf("%d %d\n",x,p);
	a[x]=p;
	for(int y:f[x])
		gmax(l[y],p+1);
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(n,m,k);
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1;i<=m;i++){
		int x,y;read(x,y);
		g[x].pb(y);f[y].pb(x);
	}
	if(!check()){puts("-1");return 0;}
	clr(vis,0);
	for(int i=1;i<=n;i++)
		if(!vis[i]) dfs(i);
	clr(vis,0);
	for(int i=1;i<=n;i++)
		if(!vis[i]) idfs(i);
	
//	for(int i=1;i<=n;i++) 
//		printf("%d %d\n",l[i],r[i]);
	for(int i=1;i<=n;i++)
		ins[l[i]].pb(i);
	static heap(pii) q;
	for(int i=1;i<=k;i++){
		bool isok=0;
		for(int j:ins[i])
			q.push(mp(r[j],j));
		while(!q.empty()){
			int j=q.top().SS;
			if(l[j]>i){
				q.pop();ins[l[j]].pb(j);
				continue;
			}
			if(!isok||r[j]==i){
				q.pop();upt(j,i);
				isok=1;
			}
			else break;
		}
		if(!isok){debug(i);puts("-1");return 0;}
		ins[i].clear();
	}
	for(int i=1;i<=n;i++)
		if(!a[i]){puts("-1");return 0;}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);puts("");
	return 0;
}