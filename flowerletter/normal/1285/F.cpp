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
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 1e5+10;
int n,a[MAXN],tim[MAXN],cnt[MAXN],vis[MAXN],mu[MAXN];
ll ans;
template<class T>inl void ylmin(T &a,T b){a=a<b?a:b;}
template<class T>inl void ylmax(T &a,T b){a=a>b?a:b;}
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
template<class T>struct Stack{
	int Top,buf[MAXN];
	inl bool empty(){return Top==0;}
	inl void clear(){Top=0;}
	inl int top(){return buf[Top];}
	inl void pop(){Top--;}
	inl void push(int x){buf[++Top]=x;}
};
Stack<int> S;
vector<int> prim,g[MAXN];
inl void init(){
	mu[1]=1;
	rep(i,2,1e5){
		if(!vis[i]) mu[i]=-1,prim.pb(i);
		for(auto j:prim){
			if(j*i>1e5) break;
			vis[i*j]=1;
			if(i%j==0) break;
			mu[i*j]=-mu[i];
		}
	}
	rep(i,1,1e5) for(int j=i;j<=1e5;j+=i) g[j].pb(i);
}
inl bool check(int x){
	int res=0;
	for(auto f:g[x]) res+=cnt[f]*mu[f];
	return res>0;
}
inl void update(int x,int k){
	for(auto f:g[x]) cnt[f]+=k;
}
int main(){
	//freopen("in.txt","r",stdin);
	init();
	read(n);
	rep(i,1,n) read(a[i]),tim[a[i]]++;
	rep(gcd,1,1e5){
		per(i,1e5/gcd,1){
			if(!tim[i*gcd]) continue;
			if(tim[i*gcd]>1) ylmax(ans,1ll*i*gcd);
			while(!S.empty() && check(i)){
				ylmax(ans,1ll*gcd*i*S.top());
				update(S.top(),-1),S.pop();
			}
			update(i,1);S.push(i); 
		}
		while(!S.empty()) update(S.top(),-1),S.pop();
	}
	printf("%lld\n",ans);
	return 0;
}