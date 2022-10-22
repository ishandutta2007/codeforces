/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
const int MAXN = 3e5 + 10;
int T,n,a[MAXN];
int main(){
//	freopen("in.txt","r",stdin);
	for(read(T);T;T--){
		read(n);
		int flag=1;
		rep(i,1,n) read(a[i]),flag&=(a[i]==a[1]);
		if(flag){
			puts("-1");
			continue;
		}
		if(n==1) {
			puts("1");
			continue;
		}
		int Max=*max_element(a+1,a+n+1);
		rep(i,1,n) {
			if(a[i]!=Max) continue;
			if(i==1 && a[2]<a[1]) {
				puts("1");
				break;
			}
			else if(i==n && a[n-1]<a[n]) {
				printf("%d\n",n);
				break;
			}
			else if(i!=1 && i!=n && (a[i-1]<a[i] || a[i+1]<a[i])){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}