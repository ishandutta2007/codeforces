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
const int MAXN = 2e5+10;
char s[MAXN],t[MAXN];
ll n,a,b,l,r,T;
vector<pll > A;
ll ans;
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
	for(int i=1;i<=n+1;i++)t[i]='0';
	ans=0,l=1,r=n+1;
	A.clear();
}
int main(){
	//freopen("in.txt","r",stdin);
	for(cin>>T;T;T--){
		cin>>n>>a>>b;Init();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++) if(s[i]=='1') t[i]=t[i+1]='1';
		for(int i=1;i<=n+1;i++) s[i]=t[i];
		//for(int i=1;i<=n+1;i++) cout<<t[i];putchar(' ');
		while(s[l]=='0' && l<=n+1) l++,ans+=a+b;
		if(l==n+2) {printf("%lld\n",ans-a);continue;}
		while(s[r]=='0' && r>=1) r--,ans+=a+b;
		ans+=2*a;
		for(int i=l+1,now=1;i<=r+1;i++)
			if(s[i]==s[i-1]) now++;
			else A.pb(mp(s[i-1]-'0',now)),now=1; 
		for(int i=0;i<A.size();i++) 
		    if(A[i].fir==1) ans+=(A[i].sec-1)*a+A[i].sec*b*2ll;
		    else ans+=min((A[i].sec+1)*a+A[i].sec*b*2ll,A[i].sec*b+(A[i].sec-1ll)*a+4ll*a); 
		printf("%lld\n",ans);
	}
	return 0;
}