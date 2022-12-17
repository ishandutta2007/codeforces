//#include "debug.h"
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef double real;
const real pi=acos(-1.0);//NOTES:pi
typedef long long i64;
typedef unsigned long long u64;
const int intmax=0x3f3f3f3f;//NOTES:intmax
//const i64 i64max=0x3f3f3f3f3f3f3f3fi64;//NOTES:i64max
real eps=1e-6;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
inline int rand(int a, int b) {if(a >= b) return a; return rand() % (b-a) + a;}//NOTES:rand(
//Numberic Functions
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
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
#define For(i, a, b) for(int i=a; i<b; ++i)//for
#define ff(i, b) for(int i=0; i<b; ++i)
struct vec2{
    real x, y;
    vec2(real x=0.0, real y=0.0):x(x), y(y){}
    vec2 operator+(const vec2 &b)const{ return vec2(x+b.x, y+b.y);}
    vec2 operator-(const vec2 &b)const{ return vec2(x-b.x, y-b.y);}
    vec2 operator*(const real &b)const{ return vec2(x*b, y*b);}
    vec2 operator/(const real &b)const{ return vec2(x/b, y/b);}
    real operator*(const vec2 &b)const{ return x*b.x + y*b.y;}
    real operator^(const vec2 &b)const{ return x*b.y - y*b.x;}
    real len(){return sqrt(x*x+y*y);}
    vec2 unit(){ return *this/len();}
    vec2 rotate(real r){vec2 t(sin(r), cos(r));return vec2(*this ^ t, *this * t);}
    bool operator<(const vec2 &b)const{
        if(dblcmp(x, b.x) != 0) return dblcmp(x, b.x) < 0;
        else return dblcmp(y, b.y) < 0;
    }
};

const int N = 1510;
struct NODE{
    int v, next;
}node[N], edge[N*2];
int tot;
int son[N], pre[N], ds[N];
void clear(){
    tot = 0;
    mem(son, 0xff);
    mem(node, 0xff);
    mem(pre, 0xff);
    mem(ds, 0);
}

void addEdge(int a, int b){
    edge[tot].next = node[a].next;
    edge[tot].v = b;
    node[a].next = tot ++;
}

void dfs(int u){
    if(son[u] != -1) return;
    son[u] = 1;
    ds[u] = 0;
    for(int i=node[u].next; i!=-1; i=edge[i].next){
        int v = edge[i].v;
        if(pre[v] != -1) continue;
        pre[v] = u;
        dfs(v);
        ds[u] ++;
        son[u] += son[v];
    }
}
vec2 p[N];
int fa[N], fb[N];
int temp;
int n;
bool cmp(const int a, const int b){
    vec2 va = p[a] - p[temp], vb = p[b] - p[temp];
    return dblcmp(va ^ vb, 0.0) < 0;
}

void gao(int u, int s, int t){
    if(s+1 == t){
        fb[fa[s]] = u;
        return;
    }
    for(int i=s+1; i<t; ++i){
        if(p[fa[i]] < p[fa[s]]){
            swap(fa[i], fa[s]);
        }
    }
    temp = fa[s];
    fb[temp] = u;
    sort(fa+s+1, fa+t, cmp);
    int cnt = s+1;
    for(int i=node[u].next; i!=-1; i=edge[i].next){
        int v = edge[i].v;
        if(pre[v] != u) continue;
        gao(v, cnt, cnt+son[v]);
        cnt += son[v];
    }
}

int main(){
    int a, b;
    while(scanf("%d", &n) != EOF){
        clear();
        for(int i=0; i<n-1; ++i){
            scanf("%d%d", &a, &b);
            addEdge(a, b);
            addEdge(b, a);
        }
        for(int i=1; i<=n; ++i){
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        pre[1] = 0;
        dfs(1);
        for(int i=0; i<=n; ++i){
            fa[i] = i;
        }
        gao(1, 1, n+1);
        for(int i=1; i<=n; ++i){
            printf("%d%c", fb[i], i==n?'\n':' ');
        }
    }
    return 0;
}