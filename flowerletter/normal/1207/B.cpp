#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define inl inline
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define lson root<<1
#define rson root<<1|1
const int MAXN = 55;
int n,m,a[MAXN][MAXN],b[MAXN][MAXN];
vector<pii > Ans;
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
inl bool check(){
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++) if(a[i][j]!=b[i][j]) return false;
	printf("%d\n",Ans.size());
	return true;
}
int main(){
	//freopen("in.txt","r",stdin);
	read(n),read(m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(b[i][j]);
	for(int i=1;i<n;i++)
	    for(int j=1;j<m;j++) if(b[i][j]==1 && b[i][j+1]==1 && b[i+1][j]==1 && b[i+1][j+1]==1) Ans.pb(mp(i,j)),a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]=1;
	if(check()) for(int i=0;i<Ans.size();i++) printf("%d %d\n",Ans[i].fir,Ans[i].sec);
	else puts("-1");
	return 0;
}