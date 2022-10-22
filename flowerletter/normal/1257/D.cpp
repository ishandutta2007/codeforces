/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
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
const int MAXN = 2e5+10;
int T,n,m,Max[MAXN][20],a[MAXN],Log2[MAXN];
struct Node{int p,s;bool used;}b[MAXN]; 
vector<Node> c;
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
inl int Query(int l,int r){
	int k=Log2[r-l+1];
	return max(Max[l][k],Max[r-(1<<k)+1][k]);
}
inl bool cmp(Node a,Node b){
	return a.s==b.s?a.p>b.p:a.s>b.s;
}
inl int find(int tmp){
	int l=0,r=c.size()-1,ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(c[mid].s>=tmp) ans=mid,l=mid+1;
		else r=mid-1;
	}return ans;
}
int main(){
//	freopen("in.txt","r",stdin);
	for(read(T);T;T--){
		c.clear();
		read(n);int mjy=0;
		rep(i,1,n)read(a[i]),mjy=max(mjy,a[i]);
		rep(i,2,n)Log2[i]=Log2[i>>1]+1;
		rep(i,1,n)Max[i][0]=a[i];
		rep(i,1,19)rep(j,1,n-(1<<i)+1) Max[j][i]=max(Max[j][i-1],Max[j+(1<<i-1)][i-1]); 
		read(m);
		rep(i,1,m)read(b[i].p),read(b[i].s),b[i].used=0;
		sort(b+1,b+m+1,cmp);int nowmax=b[1].p;b[1].used=1;
		rep(i,2,m) if(b[i].p>nowmax) b[i].used=1,nowmax=b[i].p;
		rep(i,1,m) if(b[i].used) c.pb(b[i]);
		if(nowmax<mjy) {puts("-1");continue;}
		int now=1,day=0;
		while(now<=n){
			int l=1,r=n-now+1,ans=0;
			while(l<=r){
				int mid=l+r>>1;int Pos=find(mid);
				if(Pos==-1) r=mid-1;
				else if(Query(now,now+mid-1)<=c[Pos].p) ans=mid,l=mid+1;
				else r=mid-1;
			}
			++day,now+=ans;
		}printf("%d\n",day);
	}
	return 0;
}