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
int n,k,a[MAXN],Set[MAXN],in[MAXN]; 
deque<int> Q;
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
	read(n),read(k);
	for(int i=1;i<=n;i++)read(a[i]);
	memcpy(Set,a,sizeof(a));
	sort(Set+1,Set+n+1);
	int *end=unique(Set+1,Set+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(Set+1,end,a[i])-Set;
	for(int i=1;i<=n;i++){
		if(!in[a[i]]) Q.push_front(a[i]),in[a[i]]=1;
		if(Q.size()>k) in[Q.back()]=0,Q.pop_back();
	}printf("%d\n",Q.size());
	while(!Q.empty()) printf("%d ",Set[Q.front()]),Q.pop_front(); 
	return 0;
}