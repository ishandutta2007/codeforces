#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef double ld;
typedef long long L;
typedef long double lf;
typedef unsigned int uint;
typedef unsigned long long uL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f,mo=1e9+7;
template<typename A,typename B>inline bool upmx(A&x,const B&y){return x<y?x=y,1:0;}
template<typename A,typename B>inline bool upmn(A&x,const B&y){return x>y?x=y,1:0;}
template<typename T>inline T gcd(T x,T y){for(;y;swap(x,y))x%=y;return x;}
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
const int N=2011;
int n,a,b;
ld f[N],g[N],u[N],v[N];
int F[N],G[N];
void W(ld k){
	rep(i,0,a)f[i]=F[i]=0;
	rep(i,1,n){
		swap(f,g),swap(F,G);
		f[0]=g[0],F[0]=G[0];
		if(upmx(f[0],g[0]-k+v[i]))F[0]=G[0]+1;
		rep(j,1,a){
			f[j]=g[j],F[j]=G[j];
			if(upmx(f[j],g[j-1]+u[i]))F[j]=G[j-1];
			if(upmx(f[j],g[j]-k+v[i]))F[j]=G[j]+1;
			if(upmx(f[j],g[j-1]-k+v[i]+u[i]-u[i]*v[i]))
				F[j]=G[j-1]+1;
		}
	}
}
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cout.tie(0);
	cin>>n>>a>>b;
	rep(i,1,n)cin>>u[i];
	rep(i,1,n)cin>>v[i];
	ld l=-1e9,r=1e9;
	while(clock()<=4.5*CLOCKS_PER_SEC){
		ld m=(l+r)/2.0;
		W(m);
		if(F[a]<=b)r=m;
		else l=m;
	}
	printf("%.8lf\n",f[a]+l*b);
}