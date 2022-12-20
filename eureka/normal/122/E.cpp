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

const int N = 13;

lld tmp[N];

set<int> st;
int n, k;
void dfs(lld a){
	if (a > n) return;
	st.insert(a);
	dfs(a*10 + 4);
	dfs(a*10 + 7);
}

bool judge(){
	lld ans = 1;
	for (int i=1; i<=n; ++i){
		if (ans > k) break;
		ans *= i;
	}
	return ans >= k;
}

void gao(int a[], int n, int k){
	if (n == 1) return;
	int p = k / tmp[n-1];
	int t = a[p];
	for (int i=p; i>0; --i) a[i] = a[i-1];
	a[0] = t;
	gao(a+1, n-1, k%tmp[n-1]);
}

int main(){
	tmp[0] = 1;
	for (int i=1; i<N; ++i) tmp[i] = tmp[i-1] * i;
	cin >> n >> k;
	dfs(4);
	dfs(7);
	if(!judge()){
		puts("-1");
	}else {
		int ans = 0;
		int m = max(0, n-N);
		for (set<int>::iterator it=st.begin(); it!=st.end(); ++it){
			if (*it <= m){
				ans ++;
			}
		}
		int a[20];
		for (int i=0; i<n-m; ++i) a[i] = i + m + 1;
		gao(a, n-m, k-1);
		//for (int i=1; i<=m; ++i) printf("%d ", i);
		//for (int i=0; i<n-m; ++i) printf("%d ", a[i]); puts("");
		for (int i=0; i<n-m; ++i){
			if (st.find(m+1+i) != st.end() && st.find(a[i]) != st.end()) ans ++;
		}
		cout << ans << endl;
	}
	return 0;
}