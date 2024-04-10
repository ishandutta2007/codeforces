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
int T,tot,ans[26],vis[26];
vector<int> a[26];
char s[210];
inl int dfs(int now,int fa){
	ans[tot++]=now,vis[now]=1;
	int cnt=0,qwq=1;
	for(auto x:a[now]){
		if(x==fa) continue;
		if(!vis[x]) qwq&=dfs(x,now),cnt++;
		else return 0;
	}
	return qwq && cnt<=1;
}
int main(){
	for(scanf("%d",&T);T;T--){
		int flag=1;
		tot=0;
		rep(i,0,25) ans[i]=0,vis[i]=0;
		rep(i,0,25) a[i].clear();
		scanf("%s",s+1);
		int n=strlen(s+1);
		if(n>1) a[s[1]-'a'].pb(s[2]-'a');
		rep(i,2,n-1) a[s[i]-'a'].pb(s[i-1]-'a'),a[s[i]-'a'].pb(s[i+1]-'a');
		if(n>1) a[s[n]-'a'].pb(s[n-1]-'a');
		rep(i,0,25) sort(all(a[i]));
		rep(i,0,25) a[i].erase(unique(all(a[i])),a[i].end());
		rep(k,0,25) rep(i,0,25) if(!vis[i] && size(a[i])<2) if(!dfs(i,i)) {puts("NO");flag=0;break;}
		if(!flag) continue;
		if(tot!=26) puts("NO");
		else{
			puts("YES");
			rep(i,0,tot-1) putchar(ans[i]+'a');
			puts("");
		}
	}
	return 0;
}