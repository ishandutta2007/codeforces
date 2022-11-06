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
const int N=1e5+11;
int t[N];
int a,b,c;
void pr(int x){
	a=b=c=0;
	while(x){
		if(x>=3&&t[x-3])++a,x-=3;
		if(x>=5&&t[x-5])++b,x-=5;
		if(x>=7&&t[x-7])++c,x-=7;
	}
	printf("%d %d %d\n",a,b,c);
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
	//ios::sync_with_stdio(0);
#endif
	t[0]=1;
	rep(i,1,1000){
		if(i>=3)t[i]|=t[i-3];
		if(i>=5)t[i]|=t[i-5];
		if(i>=7)t[i]|=t[i-7];
	}
	int T,x;
	cin>>T;
	while(T--){
		cin>>x;
		if(!t[x])puts("-1");
		else pr(x);
	}
}