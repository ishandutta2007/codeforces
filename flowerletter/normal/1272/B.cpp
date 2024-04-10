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
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 1e5+10;
int T,cnt[26];
char s[MAXN];
template<class T>inl void ylmin(T &a,T b){a=min(a,b);}
template<class T>inl void ylmax(T &a,T b){a=max(a,b);}
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
//	freopen("in.txt","r",stdin);
	for(scanf("%d",&T);T;T--){
		memset(cnt,0,sizeof(cnt));
		memset(s,'\0',sizeof(s));
		scanf("%s",s+1);
		rep(i,1,strlen(s+1)) cnt[s[i]-'A']++;
		int u=min(cnt['U'-'A'],cnt['D'-'A']),v=min(cnt['L'-'A'],cnt['R'-'A']);
		if(u==0) v=min(v,1);
		if(v==0) u=min(u,1);
		printf("%d\n",u+u+v+v);
		rep(i,1,u) putchar('U');
		rep(i,1,v) putchar('R');
		rep(i,1,u) putchar('D');
		rep(i,1,v) putchar('L');
		puts("");
	}
	return 0;
}