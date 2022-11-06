#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin())i=a.begin();i!=a.end();++i)
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
const int inf=0x3f3f3f3f,mo=998244353;
template<typename A,typename B>inline bool upmx(A&x,const B&y){return x<y?x=y,1:0;}
template<typename A,typename B>inline bool upmn(A&x,const B&y){return x>y?x=y,1:0;}
template<typename T>inline T gcd(T x,T y){for(;y;swap(x,y))x%=y;return x;}
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

const int N=5e5+11;
char s[N];
L ans;
void work(int l,int r){
	if(l>r)return;
	int i;
	for(i=l;i<=r;++i)if(s[i]=='0')break;
	int n=r-l+1,m=l+r>>1;
	if(i>r){
		//cerr<<"n="<<n<<endl;
		rep(i,1,n)ans+=1ll*i*(i+1)/2;
		return;
	}
	if(l==r)return;
	int w=inf,p=0;
	rep(i,l,r)if(s[i]=='0'){
		if(upmn(w,abs(i-m)))p=i;
	}
	//cerr<<"p="<<p<<endl;
	if(p>m)--p;
	//if(p<m)++p;
	//cerr<<l<<" "<<r<<" "<<p<<endl;
	work(l,p);
	work(p+1,r);
	int f[n+1],g[n+1];
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	int now=0,mx=0;
	rep(i,p+1,r){
		if(s[i]=='1')++now;
		else now=0;
		upmx(mx,now);
		f[mx]++;
	}
	now=0;
	mx=0;
	per(i,l,p){
		if(s[i]=='1')++now;
		else now=0;
		upmx(mx,now);
		g[mx]++;
	}
	rep(i,1,n)f[i]+=f[i-1];
	rep(i,1,n)g[i]+=g[i-1];
	rep(i,1,n){
		if(!f[i]&&!g[i])break;
		ans+=i*(1ll*f[i]*g[i]-1ll*f[i-1]*g[i-1]);
	}
}
int n;
int main(){
#ifdef flukehn
	freopen("c.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>n>>s+1;
	work(1,n);
	cout<<ans<<endl;
}