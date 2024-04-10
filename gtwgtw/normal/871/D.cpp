#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define REP(i, x, y) for(int i = (int)x; i <= (int)y; i ++)
#define FOR(i, x, y) for(int i = (int)x; i <  (int)y; i ++)
#define PER(i, x, y) for(int i = (int)x; i >= (int)y; i --)
#define trace(x) cerr << #x << " " << x << endl;
#define dprintf(...) fprintf(stderr, __VA__ARGS__)
#define dln()        fprintf(stderr, "\n")
using namespace std;
typedef long long LL;
typedef long double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPI;
const	int N = 10000005;
const	int P = 1e9 + 7;
const	int inf = 1e9;
const	LL Inf = 1e15;

inline int IN(){
	char ch = getchar(); int x = 0, f = 0;
	while(ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}
	return f ? (-x) : x;
}

inline int Pow(int x, int y, int p){
	int an = 1;
	for(; y; y >>= 1, x = (LL)x * x % p) if(y & 1) an = (LL)an * x % p;
	return an;
}

void renew(int &x, int y){
	x += y;
	if(x < 0) x += P;
	else if(x >= P) x -= P;
}

void setIO(string a){
#ifndef LOCAL
	freopen((a + ".in").c_str(), "r", stdin);
	freopen((a + ".out").c_str(), "w", stdout);
#else
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int n;
int d[105][105];
int mu[N],minp[N],pr[N/10],tot;
bool vis[N];
int sum[N];
LL ans;

int ask(int l,int r){
	if(l>r)return 0;
	return sum[r]-sum[l-1];
}

int gcd(int x,int y){
	if(!y) return x;
	return gcd(y,x%y);
}

int main(){
#ifdef LOCAL
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d",&n);
	
	if(n<=100){
		REP(i,1,n) REP(j,1,n) if(gcd(i,j)>1) d[i][j]=1; else d[i][j]=1<<25;
		REP(i,1,n) d[i][i]=0;
		REP(k,1,n) REP(i,1,n) REP(j,1,n) if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
		LL ans=0;
		REP(i,1,n) FOR(j,1,i) if(d[i][j]<1e7) ans+=d[i][j];
		cout<<ans<<endl;
		return 0;
	}

	mu[1]=1;
	REP(i,2,n){
		if(!vis[i]){
			mu[pr[++tot]=i]=-1;
			minp[i]=i;
		}
		for(int k=1;k<=tot&&1LL*i*pr[k]<=n;k++){
			vis[i*pr[k]]=1;
			minp[i*pr[k]]=pr[k];
			if(i%pr[k]==0){
				mu[i*pr[k]]=0;
				break;
			}else{
				mu[i*pr[k]]=-mu[i];
			}
		}
	}

	memset(sum,0,sizeof sum);
	REP(p,2,n/2) sum[p]=sum[p-1]+(1-vis[p]);
	REP(p,n/2+1,n) sum[p]=sum[p-1];


	REP(p,2,n/2) if(!vis[p]){
		ans+=2LL*ask(p+1,n/p);
		ans+=3LL*ask(max(p+1,n/p+1),n/2);
	}

	memset(sum,0,sizeof sum);
	REP(p,2,n) if(vis[p]) sum[minp[p]]++;
	REP(p,2,n) sum[p]=sum[p-1]+sum[p];

	REP(p,2,n/2) if(!vis[p]){
		int A=n/p-1,B=sum[n/p];
		for(int j=p+p;j<=n;j+=p) if(minp[j]<=n/p) B--;
		int C=sum[n]-A-B;
		ans+=A;
		ans+=2LL*B;
		ans+=3LL*C;
	}

	memset(sum,0,sizeof sum);
	REP(i,1,n) sum[i]=sum[i-1]+vis[i];
	LL res=0;
	REP(d,1,n) if(mu[d]){
		int ff=0;
		if(d==1) ff=sum[n]; else ff=n/d-(1-vis[d]);
		res+=1LL*mu[d]*ff*(ff-1)/2;
	}

	LL d1=(LL)sum[n]*(sum[n]-1)/2-res;

	ans+=d1+2*res;

	printf("%lld\n",ans);


	return 0;
}