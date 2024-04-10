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
const int MAXN = 4010;
const int MAXM = 20010;
const int block = sqrt(4000);
int n,p,q,cnt,c[MAXN],h[MAXN],t[MAXN],rev[MAXM],ans[MAXM],a,b;
vector<pii> Q[MAXM];
struct Node{
	int a[MAXN];
	Node (){memset(a,0,sizeof a);}
	int& operator [] (int x){return a[x];}
	inl void print(){
		rep(i,1,14) cout<<a[i]<<' ';
		puts("");
	}
};
struct Stack{
	int Top=0;
	Node S[MAXN];
	inl void push(Node x){S[++Top]=x;}
	inl bool empty(){return Top==0;}
	inl void pop(){Top--;}
	inl Node top(){return S[Top];}
}S1,S2;
stack<int> S;
vector<int> add[MAXM],del[MAXM];
inl Node Merge(Node last,int id){
	Node nw=last;
	rep(i,1,4000) if(i>=c[id]) ylmax(nw[i],last[i-c[id]]+h[id]);
	return nw;
}
inl void rebuild(){
	Node nw;
	while(!S2.empty()) {
		nw=Merge(nw,S.top());
		S1.push(nw);
		S2.pop(),S.pop();
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(p);
	rep(i,1,n) read(c[i]),read(h[i]),read(t[i]),add[t[i]].pb(i),del[min(20001,t[i]+p)].pb(i);
	read(q);
	rep(i,1,q){
		read(a),read(b);
		Q[a].pb({b,i});
	}
	rep(i,1,20000){
		for(auto id:del[i]){
			if(S1.empty()) rebuild();
			S1.pop();
		}
		for(auto id:add[i]){
			if(S2.empty()){
				Node nw;
				S2.push(Merge(nw,id));
			}
			else S2.push(Merge(S2.top(),id));
			S.push(id);
		}
		for(auto x:Q[i]){
			if(S1.empty()) ans[x.sec]=S2.top()[x.fir];
			else if(S2.empty()) ans[x.sec]=S1.top()[x.fir];
			else {
				Node a=S1.top(),b=S2.top();
				rep(i,0,x.fir) ylmax(ans[x.sec],b[i]+a[x.fir-i]);
			}
		}
	}
	rep(i,1,q) printf("%d\n",ans[i]);
	return 0;
}