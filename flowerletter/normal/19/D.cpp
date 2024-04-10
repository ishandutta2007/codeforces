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
int n,m,x,y;char opt[10];
vector<int> Setx,Sety;
multiset<int> S[MAXN];
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
struct Que{int type,x,y;}Q[MAXN];
struct Node{int Max,Pos;}tree[MAXN<<2];
inl void PushUp(int root){
	if(tree[lson].Max>=tree[rson].Max) tree[root]=tree[lson];
	else tree[root]=tree[rson];
}
inl void update(int root,int l,int r,int Pos,int val){
	if(l==r)return tree[root].Max=val,tree[root].Pos=Pos,void();
	if(Pos<=Mid) update(lson,l,Mid,Pos,val);
	else update(rson,Mid+1,r,Pos,val);
	PushUp(root);
}
inl pii Query(int root,int l,int r,int Pos,int val){
	if(l==r) return {tree[root].Max,tree[root].Pos};
	if(Pos>Mid) return Query(rson,Mid+1,r,Pos,val);
	pii mjy;
	if(tree[lson].Max>val) mjy=Query(lson,l,Mid,Pos,val);
	if(mjy.fir>val) return mjy;
	else return Query(rson,Mid+1,r,Pos,val);
}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s%d%d",opt+1,&Q[i].x,&Q[i].y);
		Setx.pb(Q[i].x),Sety.pb(Q[i].y);
		Q[i].type=(opt[1]=='a')?1:((opt[1]=='r')?2:3);
	}
	sort(all(Setx)),Setx.erase(unique(all(Setx)),Setx.end());
	sort(all(Sety)),Sety.erase(unique(all(Sety)),Sety.end());
	rep(i,1,n) Q[i].x=lower_bound(all(Setx),Q[i].x)-Setx.begin()+1,
			   Q[i].y=lower_bound(all(Sety),Q[i].y)-Sety.begin()+1; 
	rep(i,1,n){
		if(Q[i].type==1) {
			S[Q[i].x].insert(Q[i].y);
			update(1,1,n,Q[i].x,*--S[Q[i].x].end());
		}
		else if(Q[i].type==2) {
			S[Q[i].x].erase(S[Q[i].x].find(Q[i].y));
			if(S[Q[i].x].empty()) update(1,1,n,Q[i].x,0);
			else update(1,1,n,Q[i].x,*--S[Q[i].x].end());
		}else{
			pii tmp=Query(1,1,n,Q[i].x+1,Q[i].y); 
			if(tmp.fir<=Q[i].y) puts("-1");
			else {
				auto num=S[tmp.sec].upper_bound(Q[i].y);
				printf("%d %d\n",Setx[tmp.sec-1],Sety[*num-1]);
			}
		}
	} 
	return 0;
}