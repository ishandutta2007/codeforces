#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin())i=a.begin();i!=a.end();++i)
#define fi first
#define se second
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
typedef vector<int> VI;
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
int a[N];
int n;
char s[N],t[N];
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
	//ios::sync_with_stdio(0);
#endif
	int T;
	cin>>T;
	while(T--){
		cin>>n>>s+1;
		rep(i,1,n)s[i]-='0';
		int i,j;
		int lst=-1,ans=0;
		VI e;
		for(i=1;i<=n;i=j){
			for(j=i;s[j]==s[i]&&j<=n;++j){
			}
			e.pb(j-i);
		}
		int m=SZ(e),t=0;
		for(i=0;i<m;++i){
			if(!e[i])continue;
			++ans;
			if(t<i)t=i;
			if(e[i]==1){
				while(t<m&&e[t]<=1)++t;
				if(t<m)e[t]--;
				else --m;
			}
		}
		cout<<ans<<"\n";
	}
}