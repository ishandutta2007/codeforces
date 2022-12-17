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

#define INF 2100000000
#define V 10000
#define E 1000000
struct NODE{
	int max, v;
	int next;
}node[V], edge[E];
int dis[V], countDis[V], tot;
int v;

int dfs(int s, int t){
	int flow = INF, a, u, min, mark, temp;
	int stack[V], top=0;
	int i;
	u = s;
	while(dis[s] < v){
		a = node[u].v;
		if(a != -1 && edge[a].max && dis[edge[a].v]+1 == dis[u]){
			stack[top++] = a;
			if(edge[a].v == t)
				break;
			u = edge[a].v;
		}
		else{
			if(dis[u] != 0 && countDis[dis[u]-1] == 0)
				return 0;
			min = INF;
			mark = -1;
			for(i=node[u].next; i!=-1; i=edge[i].next){
				if(edge[i].max && dis[edge[i].v]<min){
					min = dis[edge[i].v];
					mark = i;
				}
			}
			node[u].v = mark;
			temp = dis[u];
			countDis[dis[u]] --;
			dis[u] = min+1;
			if(dis[u] > v) dis[u] = v;
			countDis[dis[u]] ++;
			if(top && temp != dis[u]){
				top--;
				u = edge[stack[top]^1].v;
			}
		}
	}
	if(top == 0)
		flow = 0;
	else{
		for(i=0; i<top; i++){
			if(edge[stack[i]].max < flow)
				flow = edge[stack[i]].max;		
		}
		for(i=0; i<top; i++){
			edge[stack[i]].max -= flow;
			edge[stack[i]^1].max += flow;
		}
	}
	return flow;
}

int SAP(int s, int t){
	int flow=0, temp;
	memset(dis, 0, sizeof(dis));
	memset(countDis, 0, sizeof(countDis));
	countDis[0] = v;
	while(temp = dfs(s, t))
		flow += temp;
	return flow;
}

void init(void){
	tot = 0;
	memset(node, 0xff, sizeof(node));
}

int forb;
void addEdge(int a, int b, int c){
	if (a == forb || b == forb) return;
	edge[tot].max = c;
	edge[tot].v = b;
	edge[tot].next = node[a].next;
	node[a].next = tot++;

	node[a].v = tot-1;

	edge[tot].max = 0;
	edge[tot].v = a;
	edge[tot].next = node[b].next;
	node[b].next = tot++;
}

void addEdge2(int a, int b, int c){
	if (a == forb || b == forb) return;
	edge[tot].max = c;
	edge[tot].v = b;
	edge[tot].next = node[a].next;
	node[a].next = tot++;

	node[a].v = tot-1;

	edge[tot].max = c;
	edge[tot].v = a;
	edge[tot].next = node[b].next;
	node[b].next = tot++;
}
const int N = 1100;
int row[N] = {0}, col[N] = {0};
int no[4*N] = {0};

int main(){
	init();
	int n, m;
	int ta, tb;
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		scanf("%d%d", &ta, &tb);
		row[ta] = 1;
		col[tb] = 1;
		no[ta] = 1;
		no[3*n+1-ta] = 1;
		no[tb+n] = 1;
		no[4*n+1-tb] = 1;
	}
	if (n % 2 == 1){
		forb = n / 2 + 1;
	}else {
		forb = -1;
	}
	v = n * 4 + 2;
	int s = n * 4 + 1, t = n * 4 + 2;
	for (int i=2; i<n; ++i){
		addEdge2(i, 3*n+1-i, 1);
		addEdge2(i, 4*n+1-i, 1);
		addEdge2(i, 2*n+1-i, 1);
	}
	for (int i=2+n; i<n+n; ++i){
		addEdge2(i, 5*n+1-i, 1);
		addEdge2(i, 4*n+1-i, 1);
	}
	for (int i=2+n+n; i<n+n+n; ++i){
		addEdge2(i, 6*n+1-i, 1);
	}
	int ans = 0;
	for (int i=1; i<=4*n; ++i){
		if (i % n == 1 || i % n == 0 || no[i] == 1) continue;
		if (i % n == forb) continue;
		ans ++;
		if (i % n <= n / 2) {
			addEdge(s, i, 1);
		}else {
			addEdge(i, t, 1);
		}
	}
	if (forb != -1 && (row[forb]==0 || col[forb]==0)){
		ans ++;
	}
	ans -= SAP(s, t);
	cout << ans << endl;
	return 0;
}