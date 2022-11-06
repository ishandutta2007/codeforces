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
const int N=1e5+11;
char s[N];
pii q[N];
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n,k,x,y,p=0;
		cin>>n>>k>>s+1;
		x=y=0;
		//cerr<<"begin: "<<t<<endl;
		rep(i,1,n){
			if(s[i]=='W'){
				if(p&&p<i-1){
					q[++x]=mp(i-p-1,p+1);
					//cerr<<x<<" "<<i-p-1<<" "<<p+1<<endl;
				}
				p=i;
			}
		}
		sort(q+1,q+x+1);
		rep(i,1,x){
			if(q[i].fi>k)break;
			k-=q[i].fi;
			rep(j,q[i].se,q[i].se+q[i].fi-1)
				s[j]='W';
		}
		//if(!p)printf("%d\n",k);
		p=0;
		rep(i,1,n)if(s[i]=='W')p=i;
		per(i,1,p){
			if(!k)break;
			if(s[i]=='L'){
				--k;
				s[i]='W';
			}
		}
		rep(i,p+1,n){
			if(!k)break;
			if(s[i]=='L'){
				--k;
				s[i]='W';
			}
		}
		x=y=0;
		rep(i,1,n){
			if(s[i]=='W'){
				y+=1+x;
				x=1;
			}else x=0;
		}
		printf("%d\n",y);
	}
}