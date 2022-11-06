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
const int N=2e5+11;
int n,m;
int a[N];
int b[N];
int l;
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cout.tie(0);
	cin>>n>>m;
	l=inf;
	rep(i,1,m){
		cin>>a[i];
		int r;
		cin>>r;
		upmn(l,r-a[i]+1);
	}
	sort(a+1,a+m+1);
	For(i,0,l)b[a[1]+i]=i;
	rep(i,2,m){
		int x=a[i]+l-1,y=a[i-1];
		for(;y<a[i];)b[x--]=b[y++];
	}
	printf("%d\n",l);
	rep(i,1,n)printf("%d%c",b[i]," \n"[i==n]);
}