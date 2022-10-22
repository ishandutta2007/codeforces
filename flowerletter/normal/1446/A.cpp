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
#define ls rt<<1
#define rs rt<<1|1
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
const int MAXN = 2e5 + 10; 
int T,n; 
ll W,w[MAXN];
vector<int> ans;
int main(){
	//freopen("in.txt","r",stdin);
	for(read(T);T;T--){
		ans.clear();
		read(n),read(W);
		int flag=1;
		rep(i,1,n) {
			read(w[i]);
			if(flag&&w[i]>=(W+1)/2 && w[i]<=W) {
				printf("1\n%d\n",i);
				flag=0;
			}
		} 
		if(!flag) continue;
		ll sum=0;
		rep(i,1,n) {
			if(w[i]<=W) sum+=w[i],ans.push_back(i); 
			if(sum>=(W+1)/2) {
				printf("%d\n",size(ans));
				for(auto u:ans) printf("%d ",u);
				puts("");
				flag=0;
				break;
			} 
		}
		if(flag) puts("-1"); 
	}
	return 0;
}