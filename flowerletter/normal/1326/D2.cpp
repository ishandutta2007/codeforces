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
const int MAXN = 1000010;
const int Mod1 = 1e9+7;
const int Mod2 = 1e9+9;
const int base = 143;
pll Hash[MAXN],HASH[MAXN],Pow[MAXN];
int T,n;
char s[MAXN];
inl pll operator - (const pll a,const pll b){
	return {(a.fir-b.fir+Mod1)%Mod1,(a.sec-b.sec+Mod2)%Mod2};
}
inl pll operator * (const pll a,const pll b){
	return {a.fir*b.fir%Mod1,a.sec*b.sec%Mod2};
}
inl pll operator + (const pll a,const pll b){
	return {(a.fir+b.fir)%Mod1,(a.sec+b.sec)%Mod2};
}
inl pll get(int l,int r){
	if(r<l) return {0,0};
	return Hash[r]-Hash[l-1]*Pow[r-l+1];
}
inl pll GET(int l,int r){
	if(r<l) return {0,0};
	return HASH[l]-HASH[r+1]*Pow[r-l+1]; 
}
inl bool check(int x){
	int k=(n-x+1)/2,type=0;
	if((n-x)&1) type=1;
	rep(i,1,n-x+1) {
		if(i-1>=k){
			pll a=get(1,k-type),b=GET(k+1,i-1)+Pow[i-1-k]*GET(i+x,n); 
			if(a==b) return true;
		}
		else {
			pll a=get(1,i-1)*Pow[n-k-(i+x)+1]+get(i+x,n-k),b=GET(n-k+1+type,n);
			if(a==b) return true;
		}
	}
	return false;
}
inl void pre(){
	HASH[n+2]=HASH[n+3]=HASH[n+1]={0,0};Pow[0]={1,1};
	rep(i,1,n) Hash[i]={(Hash[i-1].fir*base+s[i])%Mod1,(Hash[i-1].sec*base+s[i])%Mod2};
	rep(i,1,n) Pow[i]={Pow[i-1].fir*base%Mod1,Pow[i-1].sec*base%Mod2};
	per(i,n,1) HASH[i]={(HASH[i+1].fir*base+s[i])%Mod1,(HASH[i+1].sec*base+s[i])%Mod2};
} 
inl void work(int x){
	int k=(n-x+1)/2,type=0;
	if((n-x)&1) type=1;
	rep(i,1,n-x+1) {
		if(i-1>=k){
			pll a=get(1,k-type),b=GET(k+1,i-1)+Pow[i-1-k]*GET(i+x,n); 
			cout<<"a:"<<1<<' '<<k-type<<','<<k+1<<' '<<i-1<<','<<i+x<<' '<<n<<'\n';
			if(a==b) {
				rep(j,1,i-1) putchar(s[j]);
				rep(j,i+x,n) putchar(s[j]); 
				return ;
			}
		}
		else {
			pll a=get(1,i-1)*Pow[n-k-(i+x)+1]+get(i+x,n-k),b=GET(n-k+1+type,n);
			cout<<"b:"<<1<<' '<<i-1<<','<<i+x<<' '<<n-k<<','<<n-k+1+type<<' '<<n<<'\n';
			if(a==b) {
				rep(j,1,i-1) putchar(s[j]);
				rep(j,i+x,n) putchar(s[j]); 
				return ;
			}
		}
	}
}
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int l=1,r=n;
		pre();
		while(s[l]==s[r] && l<=r) l++,r--;
		if(l>r) printf("%s\n",s+1);
		else {
			int ans=0,x,y;
			rep(i,l,r){
				int mid=l+i>>1;
				pll a=get(l,mid-((l+i+1)&1)),b=GET(mid+1,i);
				if(a==b) {
					if(ylmax(ans,i-l)) x=l,y=i;
				}
			}
			per(i,r,l){
				int mid=i+r>>1;
				pll a=GET(mid+1,r),b=get(i,mid-((r+i+1)&1));
				if(a==b){
					if(ylmax(ans,r-i)) x=i,y=r;
				}
			}
			rep(i,1,l-1) putchar(s[i]);
			rep(i,x,y) putchar(s[i]);
			rep(i,r+1,n) putchar(s[i]); puts("");
		}
		
	}
	return 0;
}