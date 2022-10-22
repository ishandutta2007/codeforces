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
const int MAXN = 210;
const int inf = 1e9;
char s[MAXN],t[MAXN],quq[MAXN][MAXN][MAXN];
int n,m,dp[MAXN][MAXN][MAXN];
vector<char> Ans;
struct Node{int i,j,k;}pre[MAXN][MAXN][MAXN];
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
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	rep(i,0,200) rep(j,0,200) rep(k,0,200) dp[i][j][k]=inf;
	dp[0][0][0]=0;
	rep(i,0,n) rep(j,0,m) rep(k,0,200){
		if(k!=200){
			Node next=(Node){(s[i+1]=='('?i+1:i),(t[j+1]=='('?j+1:j),k+1};
			if(dp[next.i][next.j][next.k]>dp[i][j][k]+1) 
				dp[next.i][next.j][next.k]=dp[i][j][k]+1,
				pre[next.i][next.j][next.k]=(Node){i,j,k},
				quq[next.i][next.j][next.k]='(';
		}
		if(k!=0){
			Node next=(Node){(s[i+1]==')'?i+1:i),(t[j+1]==')'?j+1:j),k-1};
			if(dp[next.i][next.j][next.k]>dp[i][j][k]+1) 
				dp[next.i][next.j][next.k]=dp[i][j][k]+1,
				pre[next.i][next.j][next.k]=(Node){i,j,k},
				quq[next.i][next.j][next.k]=')';
		}
	}
	int ans=1e9,x,y,z;
	for(int i=0;i<=200;i++) if(dp[n][m][i]+i<ans) ans=dp[n][m][i]+i,x=n,y=m,z=i;
	int more=z;
	while(x+y+z){
		Ans.pb(quq[x][y][z]);
		Node now=pre[x][y][z];
		x=now.i,y=now.j,z=now.k;
	}
	reverse(all(Ans));
	rep(i,1,more) Ans.pb(')'); 
	for(auto x:Ans) putchar(x);
	return 0;
}