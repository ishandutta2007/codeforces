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
#define lson root<<1
#define rson root<<1|1
#define mst0(x) memset(x,0,sizeof(x))
#define debug(x) printf(#x":%d\n",x)
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
#define int long long
const int Mod = 1e9+7;
int n,a[7][7],one[100],num[100],b[100][100],dp[7][(1<<20)];
vector<int> Set[100];
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
inl int Pow(int a,int b,int ans=1){
	for(;b;b>>=1,a=a*a%Mod)if(b&1)ans=ans*a%Mod;
	return ans; 
}
inl int Get(int x){
	if(one[x]) return one[x];int res=x;
	while(res) one[x]+=res&1,res>>=1;
	return one[x];
}
signed main(){
	//freopen("in.txt","r",stdin);
	read(n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)read(a[i][j]),a[i][j]=a[i][j]*Pow(100,Mod-2)%Mod;
	for(int i=0;i<(1<<n);i++)num[i]=Set[Get(i)].size(),Set[Get(i)].pb(i);
	for(int i=0;i<(1<<n);i++)for(int j=0;j<(1<<n);j++)for(int k=j;k;k=(k-1)&j)if(Get(i|k)==Get(i)+1)b[i][j]|=(1<<num[i|k]);
	dp[0][1]=1;
	for(int i=0;i<n;i++){
		for(int s=0;s<(1<<n);s++){
			ll tmp=1;
			for(int j=0;j<n;j++)if(!((s>>j)&1)) tmp=tmp*(Mod-a[i][j]+1)%Mod;else tmp=tmp*a[i][j]%Mod;
			for(int s2=0;s2<(1<<Set[i].size());s2++) {
                int res=0;
                for(int j=0;j<Set[i].size();j++)if(s2>>j&1) res|=b[Set[i][j]][s];
                dp[i+1][res]=(dp[i+1][res]+dp[i][s2]*tmp)%Mod;
            }
		}
	}printf("%lld\n",dp[n][1]);
	return 0;
}