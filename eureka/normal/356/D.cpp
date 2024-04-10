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
#define ff(I,N)    FOR(I,0,N)
#define shl(i)      ((lld)1 << (i))

const int l = 32;
const int N = 70010 + l;
const int M = N / l;
unsigned int dp[2][M] = {0};
int fb[N];
unsigned int *cur, *nxt;
int n, s;
int in[N];
struct NODE{
	int a, id;
	bool operator<(const NODE &B) const{
		if (a != B.a) return a < B.a;
		else return id < B.id;
	}
}a[N];

bool test(){
	return fb[s] != -1;
}

bool gao(int v, int id){
	int s = v / l, r = v % l;
	unsigned int ta, tb;
	for (int i=0; i<M; ++i){
		ta = cur[i] << r;
		tb = cur[i] >> (l - r);
		if (r == 0) tb = 0;
		if (i+s<M) nxt[i+s] |= ta;
		else break;
		if (i+s+1<M) {
			nxt[i+s+1] |= tb;
		}
	}
	for (int i=0; i<M; ++i){
		if (nxt[i] == cur[i]) continue;
		ta = nxt[i] ^ cur[i];
		for (int j=0; j<l && ta; ++j, ta>>=1){
			if (ta & 1){
				fb[i*l+j] = id;
			}
		}
	}
	return test();
}

bool mark[N] = {0};
int pre[N] = {0};
int main(){
	mem(fb, 0xff);
	scanf("%d%d", &n, &s);
	for (int i=0; i<n; ++i) {
		scanf("%d", &a[i].a);
		in[i+1] = a[i].a;
		a[i].id = i+1;
	}
	sort(a, a+n);
	cur = dp[0], nxt = dp[1];
	cur[0] = 1;
	nxt[0] = 1;
	fb[0] = 0;
	s -= a[n-1].a;
	if (s > 0){
		for (int i=n-2; i>=0; --i){
			if (gao(a[i].a, a[i].id)) break;
			swap(cur, nxt);
			for (int j=0; j<M; ++j) nxt[j] = cur[j];
		}
	}
	if (s<0 || !test()){
		puts("-1");
	}else {
		mem(mark, 0);
		mark[a[n-1].id] = true;
		int t, ttt=0;
		for (int i=s; i!=0; i-=in[t]){
			t = fb[i];
			if (fb[i] == -1) pre[-100000] = 1;
			if (mark[t] == true) cout << i << ' ' << in[fb[i]] << ' ' << fb[i] << endl;
			mark[t] = true;
			ttt += in[t];
		}
		for (int i=n-1; i>=0; --i){
			if (mark[a[i].id] == false){
				pre[a[i+1].id] = a[i].id;
			}
		}
		for (int i=1; i<=n; ++i){
			if (pre[i] == 0){
				printf("%d %d\n", in[i], 0);
			}else {
				printf("%d 1 %d\n", in[i]-in[pre[i]], pre[i]);
			}
		}
	}
	return 0;
}