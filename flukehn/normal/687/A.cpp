#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef double ld;
typedef long long ll;
typedef long double lf;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f,mo=1e9+7;
template<typename A,typename B>inline bool upmx(A&x,const B&y){return x<y?x=y,1:0;}
template<typename A,typename B>inline bool upmn(A&x,const B&y){return x>y?x=y,1:0;}
template<typename T>inline T gcd(T x,T y){for(;y;swap(x,y))x%=y;return x;}
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
inline int rd(){
	int x,f=1,c;for(;!isdigit(c=getchar());)f=c!='-';x=c-'0';
	for(;isdigit(c=getchar());)x=x*10+c-'0';return f?x:-x;
}
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

const int N=1e5+11;

int n,m;
vector<int> g[N];

int f[N];
int notwo;

void Dfs(int x){
	debug("%d\n",x);
	For(i,0,SZ(g[x])){
		int v=g[x][i];
		if(!f[v]){
			f[v]=-f[x];
			Dfs(v);
		}else if(f[v]!=-f[x]){
			notwo=1;
		}
	}
}
int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	n=rd(),m=rd();
	rep(i,1,m){
		int u=rd(),v=rd();
		g[u].pb(v);
		g[v].pb(u);
	}
	rep(i,1,n){
		if(!f[i]){
			f[i]=1;
			Dfs(i);
		}
	}
	if(notwo){
		puts("-1");
		return 0;
	}
	int t=0;
	rep(i,1,n)if(f[i]>0)++t;
	printf("%d\n",t);
	rep(i,1,n)if(f[i]>0)printf("%d ",i);
	printf("\n%d\n",n-t);
	rep(i,1,n)if(f[i]<=0)printf("%d ",i);
}