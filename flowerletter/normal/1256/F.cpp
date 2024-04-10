/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
const int MAXN = 2e5+10;
int cnt1[30],cnt2[30],cnt[30],n,T;
char s1[MAXN],s2[MAXN];
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
int main(){
	//freopen("in.txt","r",stdin);
	for(scanf("%d",&T);T;T--){
		bool flag=1;
		scanf("%d%s%s",&n,s1+1,s2+1);
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		rep(i,1,n)cnt1[s1[i]-'a']++,cnt2[s2[i]-'a']++;
		rep(i,0,25) if(cnt1[i]!=cnt2[i] && flag) {puts("NO");flag=0;}
		rep(i,0,25) if(cnt1[i]>1 && flag) {puts("YES");flag=0;}
		if(flag){
			memset(cnt,0,sizeof(cnt));ll sum=0;
			rep(i,1,n){
				int l=i,r;
				rep(j,1,n)if(s2[j]==s1[i]) r=j;
				sum+=(r-l+1)/2;
				while(l<r) swap(s2[l],s2[r]),l++,r--;
			}
			if(sum&1) puts("NO");else puts("YES");
		} 
	}
	return 0;
}