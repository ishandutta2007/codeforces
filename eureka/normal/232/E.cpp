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

const int N = 512;
const int Q = 600010;
char in[N][N];
bitset<N> dpl[N][N], dpr[N][N];
int l[Q], r[Q], u[Q], d[Q];
bool ans[Q];
int n, m, q;

void gao(int L, int R, vector<int> v){
	if (v.size() == 0 || L > R) return;
	vector<int> vl, vr;
	int M = (L + R) / 2;
	for (int i=n-1; i>=0; --i){
		if (in[i][M] == '#') dpl[i][M].reset();
		else {
			dpl[i][M] = dpl[i+1][M];
			dpl[i][M].set(i);
		}
	}
	for (int i=0; i<n; ++i){
		if (in[i][M] == '#') dpr[i][M].reset();
		else {
			if (i) dpr[i][M] = dpr[i-1][M];
			dpr[i][M].set(i);
		}
	}
	for (int i=n-1; i>=0; --i){
		for (int j=M-1; j>=L; --j){
			if (in[i][j] == '#'){
				dpl[i][j].reset();
			}else {
				dpl[i][j] = dpl[i+1][j] | dpl[i][j+1];
			}
		}
	}
	for (int i=0; i<n; ++i){
		for (int j=M+1; j<=R; ++j){
			if (in[i][j] == '#'){
				dpr[i][j].reset();
			}else {
				if (i) dpr[i][j] = dpr[i-1][j] | dpr[i][j-1];
				else dpr[i][j] = dpr[i][j-1];
			}
		}
	}
	for (int i=0; i<v.size(); ++i){
		int p = v[i];
		if (r[p] < M){
			vl.push_back(p);
		}else if (l[p] > M){
			vr.push_back(p);
		}else {
			ans[p] = (dpl[u[p]][l[p]] & dpr[d[p]][r[p]]).any();
			//cout << p << ' ' << dpl[l[p]][u[p]] << ' ' << dpr[r[p]][d[p]] << endl;
		}
	}
	gao(L, M-1, vl);
	gao(M+1, R, vr);
}

int main(){
	cin >> n >> m;
	for (int i=0; i<n; ++i) cin >> in[i];
	cin >> q;
	for (int i=0; i<q; ++i) {
		cin >> u[i] >> l[i] >> d[i] >> r[i];
		l[i]--, u[i] --, r[i] --, d[i] --;
	}
	vector<int> v;
	for (int i=0; i<q; ++i) v.push_back(i);
	gao(0, m-1, v);
	for (int i=0; i<q; ++i) puts(ans[i] ? "Yes" : "No");
	return 0;
}