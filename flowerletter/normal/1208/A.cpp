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
int T,a,b,n,ans;
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
	for(read(T);T;T--){
		read(a),read(b),read(n),ans=0;
		for(int i=0;i<=30;i++){
			if((a&(1<<i))==(1<<i) and (b&(1<<i))==(1<<i)) if(n%3==0 or n%3==1) ans|=(1<<i);
			if((a&(1<<i))==(1<<i) and (b&(1<<i))==0) if(n%3==0 or n%3==2) ans|=(1<<i);
			if((a&(1<<i))==0 and (b&(1<<i))==(1<<i)) if(n%3==1 or n%3==2) ans|=(1<<i);
		}
		printf("%d\n",ans);
	}
	return 0;
}