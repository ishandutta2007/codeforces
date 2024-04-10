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
struct vec2{
    real x, y;
    vec2(real x=0.0, real y=0.0):x(x), y(y){}
    vec2 operator+(const vec2 &b)const{ return vec2(x+b.x, y+b.y);}
    vec2 operator-(const vec2 &b)const{ return vec2(x-b.x, y-b.y);}
    vec2 operator*(const real &b)const{ return vec2(x*b, y*b);}
    vec2 operator/(const real &b)const{ return vec2(x/b, y/b);} real operator*(const vec2 &b)const{ return x*b.x + y*b.y;}
    real operator^(const vec2 &b)const{ return x*b.y - y*b.x;}
    real len(){return sqrt(x*x+y*y);}
    vec2 unit(){ return *this/len();}
    vec2 rotate(real r){vec2 t(sin(r), cos(r));return vec2(*this ^ t, *this * t);}
    bool operator<(const vec2 &b)const{
        if(dblcmp(x, b.x) != 0) return dblcmp(x, b.x) < 0;
        else return dblcmp(y, b.y) < 0;
    }
};

#define V 110000
#define E 3*V
struct NODE{
	long v;
	long cost;
	long next;
}node[V], edge[E];
lld dis[V];
int pre[V];
long ept;
map<int, int> nxt[V];
bool spfa(long s, long n){
	long i, u, v;
	long q[V], vis[V];
	long queue[V], head=0, tail=0;
	memset(dis, 0x3f, sizeof(dis));
	memset(q, 0, sizeof(q));
	memset(vis, 0, sizeof(vis));
    dis[s] = 0;
	queue[tail++] = s; tail %= V; 
	q[s] = 1;
	vis[s] ++;
    lld basedis;
	while(head != tail){
		u = queue[head++]; head %= V;
        basedis = dis[u];
        if(nxt[u].find(dis[u]) != nxt[u].end()){
            basedis = nxt[u][dis[u]];
        }
		q[u] = 0;
		for(i=node[u].next; ~i; i=edge[i].next){
			v = edge[i].v;
			if(dis[v] > basedis + edge[i].cost){
				dis[v] = basedis + edge[i].cost;
				if(q[v] == 0){
					queue[tail++] = v; tail %= V;
					q[v] = 1;
					vis[v] ++;
					if(vis[v] > n)
						return false;
				}
			}
		}
	}
	return true;
}

void addEdge(long a, long b, long cost){
	edge[ept].v = b;
	edge[ept].cost = cost;
	edge[ept].next = node[a].next;
	node[a].next = ept;
	ept ++;
}

void init(void){
	ept = 0;
	memset(node, 0xff, sizeof(node));
}

int in[V];
int main(){
    init();
    int v, e;
    int a, b, c, n;
    scanf("%d%d", &v, &e);
    for(int i=0; i<e; ++i){
        scanf("%d%d%d", &a, &b, &c);
        addEdge(a, b, c);
        addEdge(b, a, c);
    }
    for(int i=0; i<v; ++i){
        scanf("%d", &n);
        for(int j=0; j<n; ++j){
            scanf("%d", &in[j]);
        }
        in[n] = -1;
        int hehe = intmax;
        for(int j=n-1; j>=0; --j){
            if(in[j+1] != in[j]+1) hehe = in[j] + 1;
            nxt[i+1][in[j]] = hehe;
        }
    }
    spfa(1, v);
    if(dis[v] == lldmax) dis[v] = -1;
    cout << dis[v] << endl;
    return 0;
}