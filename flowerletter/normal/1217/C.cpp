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
#define lson root<<1
#define rson root<<1|1
#define debug(x) printf(#x":%d\n",x);
const int MAXN = 2e5+10;
char a[MAXN];
int n,T,ans;
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
inl int get(int l,int r,int res=0){
	for(int i=l;i<=r;i++)res<<=1,res+=a[i]-'0';
	return res;
}
inl bool check(int l,int r){
	for(int i=l;i<=r;i++)if(a[i]!='0') return false;
	return true;
}
map<pii,bool> Map;
int main(){
	//freopen("in.txt","r",stdin);
	for(scanf("%d",&T);T;T--){
		scanf("%s",a+1),n=strlen(a+1),ans=0,Map.clear();
		for(int len=1;len<=19;len++){
			for(int i=1;i<=n-len+1;i++){
				int l=i,r=i+len-1,t=get(l,r),beg=r-t+1;//r-beg+1==t
				if(beg>=1 && beg<=r && check(beg,l-1) && !Map.count(mp(beg,r))) ans++,Map[mp(beg,r)]=1;//,cout<<beg<<' '<<l<<' '<<r<<'\n';
			}
		}printf("%d\n",ans);
	}
	return 0;
}