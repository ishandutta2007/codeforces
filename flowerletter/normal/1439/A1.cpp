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
#define ls rt<<1
#define rs rt<<1|1
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
const int MAXN = 110;
int T,n,m,a[MAXN][MAXN];
char s[MAXN][MAXN];
bool is[MAXN*MAXN];
struct Node{
	pii x,y,z;
	friend bool operator == (Node a,Node b){
		return a.x==b.x && a.y==b.y && a.z==b.z;
	}
};
vector<Node> t;
inl bool cmp(Node a,Node b){
	if(a.x==b.x) {
		if(a.y==b.y) return a.z<b.z;
		else return a.y<b.y;
	}
	else return a.x<b.x;
}
int main(){
//	freopen("in.txt","r",stdin);
	for(scanf("%d",&T);T;T--){
		t.clear();
		scanf("%d%d",&n,&m);
		rep(i,1,n) scanf("%s",s[i]+1);
		rep(i,1,n) rep(j,1,m) a[i][j]=s[i][j]-'0';
		rep(i,1,n-1) {
			rep(j,1,m-1) {
				if(a[i][j]) {
					t.push_back({{i,j},{i+1,j},{i,j+1}});
					a[i][j]^=1;
					a[i+1][j]^=1;
					a[i][j+1]^=1;
				}
			}
		}
		rep(i,1,n-1) {
			if(a[i][m]) {
				t.push_back({{i,m},{i+1,m-1},{i,m-1}});
				t.push_back({{i+1,m},{i+1,m-1},{i,m-1}});
				a[i][m]^=1;
				a[i+1][m]^=1; 
			}
		}
		rep(i,1,m-1){
			if(a[n][i]) {
				t.push_back({{n,i},{n-1,i},{n-1,i+1}});
				t.push_back({{n,i+1},{n-1,i},{n-1,i+1}});
				a[n][i]^=1;
				a[n][i+1]^=1;
			}
		}
		if(a[n][m]){
			t.push_back({{n,m},{n-1,m},{n,m-1}});
			t.push_back({{n,m},{n-1,m},{n-1,m-1}});
			t.push_back({{n,m},{n,m-1},{n-1,m-1}});
			a[n][m]^=1;
		}
		for(auto &s:t) {
			pii x=s.x,y=s.y,z=s.z;
			if(x<=y && y<=z) s={x,y,z};
			else if(x<=z && z<=y) s={x,z,y};
			else if(y<=x && x<=z) s={y,x,z};
			else if(y<=z && z<=x) s={y,z,x};
			else if(z<=x && x<=y) s={z,x,y};
			else s={z,y,x};
		}
		sort(all(t),cmp);
		int cnt=size(t);
		rep(i,0,size(t)-1){
			if(t[i]==t[i-1] && !is[i] && !is[i-1]) {
				is[i]=is[i-1]=1;
				cnt-=2;
			}
		}
		cout<<cnt<<'\n';
		rep(i,0,size(t)-1){
			Node s=t[i];
			if(!is[i]) printf("%d %d %d %d %d %d\n",s.x.fir,s.x.sec,s.y.fir,s.y.sec,s.z.fir,s.z.sec);
		}
		rep(i,0,size(t)-1) is[i]=0;
	} 
	return 0;
}