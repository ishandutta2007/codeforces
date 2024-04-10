/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
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
typedef long long ll;
const int MAXN = 2e5+10;
const int MAXW = (1<<14)+10;
const int Size = 388;
int n,k,q,a[MAXN],b[MAXN],c[MAXN];
int cnt,mjy[MAXN],L[MAXN],R[MAXN];
bool quq[MAXN];
int num,l[MAXN],r[MAXN],rev[MAXN],w[MAXN/Size+10][MAXW],tag[MAXN];
int ans,tot;
char opt[5];
vector<int> S[MAXN];
template<class T>inl void ylmin(T &a,T b){a=min(a,b);}
template<class T>inl void ylmax(T &a,T b){a=max(a,b);}
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
inl void update(int u,int v,int val){
	int x=rev[u],y=rev[v];
	if(x==y) {
		rep(i,u,v) w[x][mjy[i]]--,mjy[i]^=val,w[x][mjy[i]]++;
		return ;
	}
	rep(i,x+1,y-1) tag[i]^=val;
	rep(i,u,r[x]) w[x][mjy[i]]--,mjy[i]^=val,w[x][mjy[i]]++;
	rep(i,l[y],v) w[y][mjy[i]]--,mjy[i]^=val,w[y][mjy[i]]++;
}
inl int query(int u,int v){
	int x=rev[u],y=rev[v],res=0;
	if(x==y){
		rep(i,u,v) res+=mjy[i]==tag[x];
		return res;
	}
	rep(i,x+1,y-1) res+=w[i][tag[i]];
	rep(i,u,r[x]) res+=mjy[i]==tag[x];
	rep(i,l[y],v) res+=mjy[i]==tag[y];
	return res; 
}
inl void update(int begin,int val){
	if(begin==n+1) return ;
	int x=begin%k,y=(begin-1)/k+L[x];
	if(quq[x]) tot-=query(R[x],R[x]);
	ans-=query(L[x],R[x]);
	update(y,R[x],val);
	if(quq[x]) tot+=query(R[x],R[x]);
	ans+=query(L[x],R[x]);
}
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&k,&q);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) scanf("%d",&b[i]);
	rep(i,1,n) c[i]=a[i]^b[i];
	rep(i,1,n) S[i%k].pb(c[i]^c[i-1]);
	rep(i,0,k-1){
		L[i]=cnt+1;
		rep(j,0,size(S[i])-1){
			if(j) S[i][j]^=S[i][j-1];
			mjy[++cnt]=S[i][j];
		}
		R[i]=cnt;quq[i]=((!i?k:i)+(size(S[i])-1)*k)!=n-k+1;
	}
	rep(i,1,n) ans+=mjy[i]==0;
	rep(i,0,k-1) if(quq[i]) tot+=mjy[R[i]]==0;
	num=(n%Size?n/Size+1:n/Size);
	rep(i,1,num){
		l[i]=r[i-1]+1,r[i]=min(l[i]+Size,n);
		rep(j,l[i],r[i]) w[i][mjy[j]]++,rev[j]=i;
	}
	printf("%d\n",tot==k-1?n-ans:-1);
	while(q--){
		int x,y;
		scanf("%s%d%d",opt+1,&x,&y);
		if(opt[1]=='a') update(x,a[x]^y),update(x+1,a[x]^y),a[x]=y;
		if(opt[1]=='b') update(x,b[x]^y),update(x+1,b[x]^y),b[x]=y;
		printf("%d\n",tot==k-1?n-ans:-1);
	}
	return 0;
}