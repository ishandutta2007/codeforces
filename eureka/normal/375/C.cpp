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
real eps=1e-8;//NOTES:eps
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
#define MP(a, b) make_pair(a, b)
#define PII pair<int, int>


struct vec2{
    int x, y;
    vec2(int x=0.0, int y=0.0):x(x), y(y){}
    vec2 operator+(const vec2 &b)const{ return vec2(x+b.x, y+b.y);}
    vec2 operator-(const vec2 &b)const{ return vec2(x-b.x, y-b.y);}
    vec2 operator*(const int &b)const{ return vec2(x*b, y*b);}
    vec2 operator/(const int &b)const{ return vec2(x/b, y/b);} 
	int operator*(const vec2 &b)const{ return x*b.x + y*b.y;}
    int operator^(const vec2 &b)const{ return x*b.y - y*b.x;}
};

const int N = 210;
const int M = 8;

int dp[N][N][1<<M];
bool inq[N][N][1<<M];
int mask[N][N][4];
char a[N][N];
int vx[] = {1, -1, 0, 0};
int vy[] = {0, 0, 1, -1};

int n, m;

struct node{
	int i, j, v;
	node(int i=0, int j=0, int v=0):i(i), j(j), v(v){}
};
queue<node> q;

void push(int i, int j, int v, int val){
	if (a[i][j] == '#' || (a[i][j] >= '1' && a[i][j] <= '8')) return;
	if (!inq[i][j][v] && val < dp[i][j][v]){
		checkmin(dp[i][j][v], val);
		q.push(node(i, j, v));
		inq[i][j][v] = true;
	}
}

void spfa(int si, int sj){
	push(si, sj, 0, 0);
	while(!q.empty()){
		node u = q.front();
		q.pop();
		inq[u.i][u.j][u.v] = false;
		int val = dp[u.i][u.j][u.v];
		for (int i=0; i<4; ++i){
			int ni = u.i + vx[i], nj = u.j + vy[i];
		   	int nv = u.v ^ mask[u.i][u.j][i];
			push(ni, nj, nv, val+1);
		}
	}
}

int px[M], py[M], val[M];
int sum[1<<M];

int cross(vec2 a, vec2 b, vec2 c, vec2 d){
	return ((d-a)^(b-a)) * ((b-a)^(c-a)) > 0 && ((b-c)^(d-c)) * ((d-c)^(a-c)) > 0;
}

int main(){
	mem(a, '#');
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
		scanf("%1s", a[n+2]);
		a[i][j] = a[n+2][0];
	}

	int t = 0;
	for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
		if (a[i][j] >= '1' && a[i][j] <= '9'){
			checkmax(t, a[i][j]-'0');
		}
	}
	fill(val, val+M, -100000);
	for (int i=0; i<t; ++i){
		scanf("%d", &val[i]);
	}
	for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
		if (a[i][j] == 'B') a[i][j] = ++t + '0';
	}
	for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
		if (a[i][j] >= '1' && a[i][j] <= '9'){
			px[a[i][j] - '1'] = i;
			py[a[i][j] - '1'] = j;
		}
	}
	for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
		for (int v = 0; v < 4; ++v){
			for (int k=0; k<t; ++k){
				int c = cross(vec2(px[k], py[k]), vec2(px[k]+n+1, py[k]+1), vec2(i, j), vec2(i+vx[v], j+vy[v]));
				mask[i][j][v] |= c << k;
			}
		}
	}
	sum[0] = 0;
	for (int i=0; i<t; ++i) sum[1<<i] = val[i];
	for (int i=1; i<1<<t; ++i) sum[i] = sum[i-lowbit(i)] + sum[lowbit(i)];
	mem(dp, 0x3f);
	int si, sj;
	for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j){
		if (a[i][j] == 'S'){
			spfa(i, j);
			si = i; 
			sj = j;
		}
	}
	int ans = 0;
	for (int i=1; i<1<<t; ++i) checkmax(ans, sum[i]-dp[si][sj][i]);
	cout << ans << endl;
	return 0;
}