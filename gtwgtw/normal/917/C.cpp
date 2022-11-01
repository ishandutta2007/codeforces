
#include <set>
#include <map>
#include <list>
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
typedef double db;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<PII> VPI;
typedef vector<long long> VL;
const	int N = 100005;
const	int P = 1e9 + 7;
const	int inf = 1e9;
const	LL Inf = 1e18;

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
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

//#define int long long

int pos[1005],val[1005],gt[1005],clz[265],x,k,n,q;
LL mat[27][95][95],ss[95],tmp[95],vec[95];
LL E[95][95],cnt,stat[265],id[265],dp[16][95];
VPI ee[95];


inline int cmp(const int &a,const int &b)
{
	return pos[a]<pos[b];
}

void Pow(int x)
{
	REP(i,0,26) if((x>>i)&1) 
	{
		REP(t,1,cnt) tmp[t]=1LL<<60;
		REP(k,1,cnt) REP(y,1,cnt) tmp[y]=min(tmp[y],vec[k]+mat[i][k][y]);
		REP(t,1,cnt) vec[t]=tmp[t];
	}
}

LL find(LL x)
{
	int l=1,r=q,aim=q+1;
	while(l<=r)
	{
		int md=(l+r)/2;
		if(pos[gt[md]]<=x)
		{
			aim=md;
			l=md+1;
		}else
		{
			r=md-1;
		}
	}
	if(aim>q) return 0;
	if(pos[gt[aim]]==x) return val[gt[aim]];
	else return 0;
}

//#undef int
int main(){
//#define	int long long
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d%d%d%d",&x,&k,&n,&q);
	memset(vec,0x3f,sizeof vec);
	
	REP(i,1,k) scanf("%lld",ss+i);
	REP(a,0,(1<<k)-1) clz[a]=clz[a>>1]+(a&1);

	memset(E,0x3f,sizeof E);
	REP(a,0,(1<<k)-1) if(clz[a]==x)
	{
		++cnt;
		stat[cnt]=a;
		id[a]=cnt;
	}
	vec[id[(1<<x)-1]]=0;

	REP(i,1,cnt)
	{
		int a=stat[i];
		if(a%2==0)
		{
			E[id[a]][id[a/2]]=0;
			ee[id[a]].pb(mk(id[a/2],-1));
		}else
		{
			int b=a>>1;
			REP(t,1,k)
			{
				if((b>>(t-1))&1) continue;
				int c=b|(1<<(t-1));
				assert(id[c]!=0);
				E[id[a]][id[c]]=ss[t];
				ee[id[a]].pb(mk(id[c],t));
			}
		}
	}

	memcpy(mat[0],E,sizeof mat[0]);

	REP(w,1,26)
	{
		memset(mat[w],0x3f,sizeof mat[w]);
		REP(k,1,cnt) REP(i,1,cnt) REP(j,1,cnt)
		{
			mat[w][i][j]=min(mat[w][i][j],mat[w-1][i][k]+mat[w-1][k][j]);
		}
	}

	bool hs=0;
	REP(i,1,q)
	{
		int dx,y;
		scanf("%d%d",&dx,&y);
		pos[i]=dx;
		if(dx==n-x+1) hs=1;
		val[i]=y;
		gt[i]=i;
	}

	if(!hs)
	{
		++q;
		pos[q]=n-x+1;
		val[q]=0;
		gt[q]=q;
	}

	sort(gt+1,gt+q+1,cmp);

	int pre=1;
	REP(z,1,q)
	{
		LL now=pos[gt[z]],valx=val[gt[z]];
		Pow(max(now-k,(LL)pre)-pre);
		{
			LL st=max(now-k,(LL)pre),ed=now;
			REP(i,0,10) REP(j,1,cnt) dp[i][j]=1LL<<60;
			REP(j,1,cnt) dp[now-st][j]=vec[j];
			PER(tt,now-st,1)
			{
				REP(j,1,cnt) for(auto k:ee[j])
				{
					LL val=E[j][k.fi];
					if(k.se!=-1)
					{
						val+=find(now-tt+k.se);
					}
					dp[tt-1][k.fi]=min(dp[tt-1][k.fi],dp[tt][j]+val);
				}
			}
		}
		REP(i,1,cnt) vec[i]=dp[0][i];
		if(now==n-x+1) break;
		pre=now;
	}

	printf("%lld\n",vec[id[(1<<x)-1]]);


	return 0;
}