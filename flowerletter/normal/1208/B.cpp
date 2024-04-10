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
const int MAXN = 2010;
int n,a[MAXN],vis[MAXN],tmp[MAXN];
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
inl bool del(int l,int r){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<l;i++) 
	    if(vis[a[i]]) return false;
	    else vis[a[i]]=1;
	for(int i=r+1;i<=n;i++)
	    if(vis[a[i]]) return false;
		else vis[a[i]]=1;
	return true;
}
inl bool check(int x){
	for(int i=1;i<=n-x+1;i++) if(del(i,i+x-1)) return true;
	return false;
}
int main(){
	//freopen("in.txt","r",stdin);
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)tmp[i]=a[i];
	sort(tmp+1,tmp+n+1);
	int size=unique(tmp+1,tmp+n+1)-tmp-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(tmp+1,tmp+n+1,a[i])-tmp;
	int l=0,r=n,ans;
	while(l<=r){
		int Mid=l+r>>1;
		if(check(Mid))ans=Mid,r=Mid-1;
		else l=Mid+1;
	}printf("%d\n",ans);
	return 0;
}