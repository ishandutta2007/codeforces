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
#define mp make_pair
#define inl inline
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define mymax(a,b) ((a)<(b)?a=b,1:0)
#define mymin(a,b) ((a)>(b)?a=b,1:0)
#define lowbit(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define mst0(x) memset(x,0,sizeof(x))
#define debug(x) printf(#x":%d\n",x)
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
const int MAXN = 2e5+10;
int T,n,dp[MAXN][2];
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
inl int type(char x){
	return (x=='1' || x=='2')?1:2;
}
int main(){
	//freopen("in.txt","r",stdin);
	for(scanf("%d",&T);T;T--){
		scanf("%d%s%s",&n,s1+1,s2+1);
		mst0(dp),dp[0][0]=1;
		for(int i=1;i<=n;i++){
			int a=type(s1[i]),b=type(s2[i]);
			if(a==1 && dp[i-1][0]) dp[i][0]=1;
			if(b==1 && dp[i-1][1]) dp[i][1]=1;
			if(a==2 && b==2 && dp[i-1][0]) dp[i][1]=1;
			if(a==2 && b==2 && dp[i-1][1]) dp[i][0]=1;
		}puts(dp[n][1]?"YES":"NO");
	}
	return 0;
}