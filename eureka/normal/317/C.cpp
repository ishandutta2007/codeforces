#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <bitset>
using namespace std;
typedef double real;
const real pi=acos(-1.0);//NOTES:pi
typedef long long lld;
typedef unsigned long long llu;
const int intmax=0x3f3f3f3f;//NOTES:intmax
const lld lldmax=0x3f3f3f3f3f3f3f3fll;//NOTES:lldmax
real eps=1e-6;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
inline int rand(int a, int b) {if(a >= b) return a; return rand() % (b-a) + a;}//NOTES:rand(
//Numberic Functions
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclid(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclid(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclid(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize(
{vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline bool isPrimeNumber(T n)//NOTES:isPrimeNumber(
{if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline T eularFunction(T n)//NOTES:eularFunction(
{vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
template<class T> inline int dblcmp(T a,const T b){a-=b; return a>eps?1:(a<-eps?-1:0);}//NOTES:doublecmp
template<class T> inline int sgn(T a){return a>eps?1:(a<-eps?-1:0);}
#define mem(a, val) memset(a, val, sizeof(a))//memset(
#define FOR(I,A,B)    for(int I = (A); I < (B); ++I)
#define REP(I,N)    FOR(I,0,N)
#define shl(i)      ((lld)1 << (i))

const int N = 310;

int mid[N][N], dis[N][N];
int cur[N], tar[N];
int n, V, e;

int ans[N*N*3][3];
int top = 0;

bool move(int s, int t, int v){
	if (v <= 0) return true;
	if (dis[s][t] > N) return false;
	if (dis[s][t] == 1){
		ans[top][0] = s+1, ans[top][1] = t+1, ans[top][2] = v;
		top ++;
		cur[s] -= v, cur[t] += v;
		return true;
	}else{
		int m = mid[s][t];
		if (cur[m] >= v){
			return move(m, t, v) && move(s, m, v);
		}else if (cur[m] + v <= V){
			return move(s, m, v) && move(m, t, v);
		}else {
			int tmp = cur[m];
			return move(m, t, tmp) && move(s, m, v) && move(m, t, v-tmp);
		}
	}
	return false;
}

int main(){
	cin >> n >> V >> e;
	for (int i=0; i<n; ++i) cin >> cur[i];
	for (int i=0; i<n; ++i) cin >> tar[i];
	mem(dis, 0x3f);
	mem(mid, 0xff);
	int a, b;
	for (int i=0; i<e; ++i){
		cin >> a >> b;
		dis[a-1][b-1] = 1;
		dis[b-1][a-1] = 1;
	}
	for (int k=0; k<n; ++k) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j){
		if (dis[i][k] + dis[k][j] < dis[i][j]){
			mid[i][j] = k;
			dis[i][j] = dis[i][k] + dis[k][j];
		}
	}
	while(true){
		int p = -1, q = -1;
		for (int i=0; i<n; ++i){
			if (cur[i] == tar[i]) continue;
			if (p == -1 || abs(tar[i]-cur[i]) < abs(tar[p]-cur[p])) p = i;
		}
		if (p == -1) break;
		for (int i=0; i<n; ++i){
			if (cur[i] == tar[i] || i == p) continue;
			if ((0LL + cur[i]-tar[i]) * (cur[p]-tar[p]) >= 0) continue;
			if (q == -1 || dis[i][p] < dis[q][p]) q = i;
		}
		if (q == -1) break;
		int val = abs(cur[p] - tar[p]);
		if (cur[p] < tar[p]) swap(p, q);
		if (!move(p, q, val)) break;
	}
	int i;
	for (i=0; i<n && cur[i] == tar[i]; ++i);
	if (i == n){
		printf("%d\n", top);
		for (i=0; i<top; ++i){
			printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
		}
	}else{
		puts("NO");
	}
	return 0;
}