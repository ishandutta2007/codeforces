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

const int V = 110000;
const int E = V * 2;

struct EDGE{
	int v, next;
}edge[E];
int node[V];
int pre[V][20];
int deep[V];
int ept = 0;
void addEdge(int a, int b){
	edge[ept].v = b;
	edge[ept].next = node[a];
	node[a] = ept ++;
}

int s[V*2], top;
vector<int> pos[V];

int getpre(int a, int n){
	for (int i=0; i<20; ++i){
		if (n & shl(i)) a = pre[a][i];
	}
	return a;
}

int gao(int a, int b){
	if (deep[a] < deep[b]) swap(a, b);
	a = getpre(a, deep[a]-deep[b]);
	for (int i=19; i>=0; --i){
		if (pre[a][i] != pre[b][i]){
			a = pre[a][i];
			b = pre[b][i];
		}
	}
	if (a != b) return pre[a][0];
	else return a;
}

int lca(int a, int b){
	//printf("lca:%d %d %d\n", a, b, deep[a] + deep[b] - 2*deep[gao(a, b)]);
	return deep[a] + deep[b] - 2*deep[gao(a, b)];
}

void dfs(int r, int f){
	pre[r][0] = f;
	deep[r] = deep[f]+1;
	for (int i=1; i<20; ++i) pre[r][i] = pre[pre[r][i-1]][i-1];
	s[top++] = r;
	pos[r].push_back(top-1);
	for (int p=node[r]; p!=-1; p=edge[p].next){
		if (edge[p].v == f) continue;
		dfs(edge[p].v, r);
		s[top++] = r;
		pos[r].push_back(top-1);
	}
}

int sum = 0;
set<int> st;
void add(int p){
	st.insert(p);
	set<int>::iterator it = st.find(p);
	int a=-1, b=-1;
	if (it != st.begin()){
		--it;
		a = *it;
		++it;
	}
	++it;
	if (it != st.end()) b = *it;
	if (a != -1 && b != -1) sum -= lca(s[a], s[b]);
	if (a != -1) sum += lca(s[a], s[p]);
	if (b != -1) sum += lca(s[p], s[b]);
}

void del(int p){
	set<int>::iterator it = st.find(p);
	int a=-1, b=-1;
	if (it != st.begin()){
		--it;
		a = *it;
		++it;
	}
	++it;
	if (it != st.end()) b = *it;
	if (a != -1 && b != -1) sum += lca(s[a], s[b]);
	if (a != -1) sum -= lca(s[a], s[p]);
	if (b != -1) sum -= lca(s[p], s[b]);
	st.erase(p);
}

int cal(){
	if (st.size() == 0) return 0;
	return (sum + lca(s[*(--st.end())], s[*st.begin()])) / 2 + 1;
}

int main(){
	mem(node, -1);
	int v, k;
	int a, b;
	cin >> v >> k;
	for (int i=1; i<v; ++i){
		cin >> a >> b;
		addEdge(a, b);
		addEdge(b, a);
	}
	dfs(1, 0);
	int ans = 0, r = 1;
	for (int i=1; i<=v; ++i){
		if (i>1) {
			for (int j=0; j<pos[i-1].size(); ++j){
				del(pos[i-1][j]);
			}
		}
		for (; r<=v; ++r){
			if (cal() <= k){
				//printf("%d %d %d\n", i, r, cal());
			   	checkmax(ans, r-i);
				for (int j=0; j<pos[r].size(); ++j){
					add(pos[r][j]);
				}
			}else {
				//printf("%d %d %d\n", i, r, cal());
				break;
			}
		}
		if (cal() <= k) checkmax(ans, r-i);
	}
	cout << ans << endl;
	return 0;
}