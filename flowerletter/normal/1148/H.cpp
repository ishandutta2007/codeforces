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
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
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
const int MAXN = 2e5+10;
int n,pos[MAXN];
ll lastans,a,l,r,k;
struct Node{
	int l1,l2,r1,r2;
	ll sum;
};
struct lastNode{
	int up,down,fir;
}t[MAXN];
vector<Node> s[MAXN];
inl ll query(int u,int x,int y){
	int l=0,r=size(s[u])-1;
	int lans=-1,rans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(s[u][mid].l2>=x && s[u][mid].r2>=x) lans=mid,r=mid-1;
		else l=mid+1;
	}
	l=0,r=size(s[u])-1;
	while(l<=r){
		int mid=l+r>>1;
		if(s[u][mid].l1<=y && s[u][mid].r1<=y) rans=mid,l=mid+1;
		else r=mid-1;
	}
	ll res=0;
	if(lans<=rans && lans!=-1 && rans!=-1){
		res=s[u][rans].sum-(lans?s[u][lans-1].sum:0);
		if(s[u][lans].l1<x) res-=1ll*(x-s[u][lans].l1)*(s[u][lans].r2-s[u][lans].r1+1);
		if(s[u][rans].l2>y) res-=1ll*(s[u][rans].l2-y)*(s[u][rans].r2-s[u][rans].r1+1);
		if(s[u][lans].r1<x){
			int ans=-1;l=0,r=size(s[u])-1;
			while(l<=r){
				int mid=l+r>>1;
				if(s[u][mid].r1<x) ans=mid,l=mid+1;
				else r=mid-1;	 
			}
			if(ans!=-1) res-=1ll*(min(s[u][ans].l2,y)-max(s[u][lans].l1,x)+1)*(x-s[u][lans].r1);
		} 
	}
	if(t[u].fir){
		int l1=max(t[u].fir,x),l2=y;
		int r1=max(t[u].down,x),r2=min(t[u].up,y);
		if(l1<=l2 && r1<=r2) res+=1ll*(l2-l1+1)*(r2-r1+1);
	}
	return res;
}
inl void end(int u,int x){
	ll sum=(s[u].empty()?0:s[u].back().sum);
	s[u].pb((Node){t[u].fir,x-1,t[u].down,t[u].up,sum+1ll*(x-t[u].fir)*(t[u].up-t[u].down+1)});
	t[u].fir=0;
}
inl void add(int x,int down,int up,int u){
	if(t[u].fir) end(u,x);
	else t[u].down=down;
	t[u].up=up,t[u].fir=x;
}
signed main(){
	read(n);
	rep(i,1,n) {
		read(a),read(l),read(r),read(k);
		a=(a+lastans)%(n+1);
		k=(k+lastans)%(n+1);
		l=(l+lastans)%i+1,r=(r+lastans)%i+1;
		if(l>r) swap(l,r);
		if(t[a].fir){
			int down=t[a].down,up=t[a].up;
			rep(x,a+1,n){
				if(pos[x]<down) {
					add(i,down,up,x);
					break; 
				}
				else if(pos[x]<up){
					add(i,pos[x]+1,up,x);
					up=pos[x];
				}
			}
			end(a,i);
		}
		add(i,i,i,!a);
		pos[a]=i;
		printf("%lld\n",lastans=query(k,l,r));
	}
	return 0;
}