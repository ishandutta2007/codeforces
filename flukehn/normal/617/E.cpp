#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > >
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define debug(...)
#endif
typedef double db;
typedef long long ll;
typedef long double lf;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int inf=~0u>>1,mo=1e9+7;
template<typename T>inline void admo(int&a,const T&b){a=(a+b>=mo?a+b-mo:a+b);}
template<typename T>inline void sumo(int&a,const T&b){a=(a-b<0?a-b+mo:a-b);}
template<typename T,typename S>inline bool upmx(T&a,const S&b){return a<b?a=b,1:0;}
template<typename T,typename S>inline bool upmn(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T>inline T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
inline int rd(){
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=1e5+11;
int n,m,k;
int a[N],b[N],c[N*20];
struct Q{
	int x,y,id;
	void in(){
		x=rd()-1;
		y=rd();
	}
	bool operator<(const Q&t)const{
		return b[x]!=b[t.x]?x<t.x:y<t.y;
	}
};
Q p[N];
ll ans[N];
ll res;
void add(int x){
	int y=a[x];
	res+=c[y^k];
	++c[y];
}
void del(int x){
	int y=a[x];
	--c[y];
	res-=c[y^k];
	
}
int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	n=rd(),m=rd(),k=rd();
	rep(i,1,n)a[i]=rd()^a[i-1];
	//rep(i,1,n)printf("%d%c",a[i]," \n"[i==n]);
	const int S=min(400,(int)sqrt(n));
	rep(i,1,n)b[i]=i/S;
	rep(i,1,m){
		p[i].in();
		p[i].id=i;
	}
	sort(p+1,p+m+1);
	int l=1,r=0;
	rep(i,1,m){
		//debug("%d %d %d %d\n",p[i].x,p[i].y,l,r)
		for(;l>p[i].x;)add(--l);
		for(;l<p[i].x;)del(l++);
		debug("%d\n",c[0]);
		for(;r<p[i].y;)add(++r);
		for(;r>p[i].y;)del(r--);
		//debug("%d %d\n",l,r)
		debug("%d\n",c[0]);
		ans[p[i].id]=res;
	}
	rep(i,1,m)printf("%lld\n",ans[i]);
}