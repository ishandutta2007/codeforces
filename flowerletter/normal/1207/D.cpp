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
const int MAXN = 3e5+10;
const int Mod = 998244353;
int n;
ll fac[MAXN],ans1=1,ans2=1,ans3=1;
pii a[MAXN],tim[MAXN];
vector<int> S[MAXN];
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
inl void Init(){
	fac[1]=fac[0]=1;
	for(int i=2;i<=n;i++) fac[i]=fac[i-1]*i%Mod;
}
inl ll Solve(int x){
	sort(S[x].begin(),S[x].end());
	ll ans=1,now=1;
	for(int i=1;i<S[x].size();i++)
	    if(S[x][i]!=S[x][i-1]) ans=ans*fac[now]%Mod,now=1;
	    else now++;
	return ans*fac[now]%Mod;
}
inl bool check(){
	int now=0;
	for(int i=1;i<=n;i++) 
	    if(S[i].size() && S[i][0]>=now) now=S[i][S[i].size()-1];
	    else if(S[i].size()) return false;
	return true;
}
int main(){
	//freopen("in.txt","r",stdin);
	read(n),Init();
	for(int i=1;i<=n;i++) read(a[i].fir),read(a[i].sec),tim[a[i].fir].fir++,tim[a[i].sec].sec++,S[a[i].fir].pb(a[i].sec);
	for(int i=1;i<=n;i++) ans1=ans1*fac[tim[i].fir]%Mod,ans2=ans2*fac[tim[i].sec]%Mod;
	for(int i=1;i<=n;i++) ans3=ans3*Solve(i)%Mod;
	if(!check()) ans3=0;
	printf("%llld\n",((fac[n]-(ans1+ans2-ans3))%Mod+Mod)%Mod); 
	return 0;
}