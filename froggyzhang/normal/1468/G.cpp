// author: xay5421
// created: Fri Dec 25 21:08:47 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,H,st[N],top,x[N],y[N];
bool vis[N];
double dis(int k1,int k2){
	return sqrt(1LL*(x[k1]-x[k2])*(x[k1]-x[k2])+1LL*(y[k1]-y[k2])*(y[k1]-y[k2]));
}
double sqr(double x){return x*x;}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(H);
	rep(i,1,n)rd(x[i]),rd(y[i]);
	rep(i,1,n){
		while(top&&1LL*(y[n]+H-y[i])*(x[n]-x[st[top]])<1LL*(y[n]+H-y[st[top]])*(x[n]-x[i]))--top;
		st[++top]=i;
	}
	rep(i,1,top)vis[st[i]]=1;
	double ans=0;
	rep(i,1,n-1){
		if(vis[i]&&vis[i+1]){
			ans+=dis(i,i+1);
		}else if(vis[i]&&!vis[i+1]){
			int pos=*upper_bound(st+1,st+1+top,i);
			double k1=1.*(y[n]+H-y[pos])/(x[n]-x[pos]);
			double b1=y[n]+H-k1*x[n];
			double k2=1.*(y[i+1]-y[i])/(x[i+1]-x[i]);
			double b2=y[i]-k2*x[i];
			double x=(b2-b1)/(k1-k2);
			double y=k2*x+b2;
			ans+=sqrt(sqr(::x[i]-x)+sqr(::y[i]-y));
		}
	}
	printf("%.20f\n",ans);
	return 0;
}