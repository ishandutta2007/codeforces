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
typedef vector<int> VI;
int n;
int a[N],c[N];
VI op[N];int tot;
void wk(VI e){
	static int b[N];
	int t=0;
	for(int y:e){
		if(y)b[++t]=y;
	}
	if(t>1){
		op[++tot]=e;
	}else{
		return;
	}
	int s=0;
	per(i,1,t){
		rep(j,1,b[i])
			c[s+j]=a[n-s-b[i]+j];
		s+=b[i];
	}
	rep(i,1,n)a[i]=c[i];
}
void pr(VI e){
	/*static int b[N];
	int t=0;
	for(int y:e){
		if(y)b[++t]=y;
	}
	int s=0;
	per(i,1,t){
		rep(j,1,b[i])
			c[s+j]=a[n-s-b[i]+j];
		s+=b[i];
	}
	rep(i,1,n)a[i]=c[i];*/
	static int b[N];
	int t=0;
	for(int y:e){
		if(y)b[++t]=y;
	}
	printf("%d ",t);
	rep(i,1,t)printf("%d%c",b[i]," \n"[i==t]);
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
#endif
	cin>>n;
	rep(i,1,n)cin>>a[i];
	//printf("%d\n",n/2*2);
	rep(i,1,n/2){
		int x,y;
		rep(j,i,n-i+1){
			if(a[j]==i)x=j;
			if(a[j]==n-i+1)y=j;
		}
		debug("xl: ");rep(i,1,n)debug("%d%c",a[i]," \n"[i==n]);
		debug("%d %d xy %d\n",i,x,y);//x<<" "<<y<<endl;
		VI u,v;
		if(x==i&&y==n-i+1){
			u.pb(n);
			v.pb(n);
		}else{
			if(x<y){
				u.pb(i-1);
				u.pb(x-i+1);
				u.pb(y-x-1);
				u.pb(n-i-y+2);
				u.pb(i-1);
				//pr(r);
				v.pb(i-1);
				v.pb(1);
				v.pb(n-2*i);
				v.pb(1);
				v.pb(i-1);
			}else{
				swap(x,y);
				u.pb(i-1);
				u.pb(x-i+1);
				u.pb(y-x-1);
				u.pb(n-i-y+2);
				u.pb(i-1);

				v.pb(i-1);
				v.pb(n-2*i+2);
				v.pb(i-1);
			}
		}
		wk(u);
		wk(v);
	}
	printf("%d\n",tot);
	rep(i,1,tot)pr(op[i]);
}