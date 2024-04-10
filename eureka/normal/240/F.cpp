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

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define pdef int l, int r, int rt=1
const int N = 110000;
int cnt[N<<2][26], lazy[N<<2];
void build(pdef){
    mem(cnt[rt], 0);
    lazy[rt] = -1;
    if(l == r){
        int v = getchar() - 'a';
        cnt[rt][v] ++;
        lazy[rt] = v;
        return;
    }
    int m = (l + r) / 2;
    build(lson);
    build(rson);
    for(int i=0; i<26; ++i) cnt[rt][i] = cnt[rt<<1][i] + cnt[rt<<1|1][i];
}

void pushdown(pdef){
    int v = lazy[rt];
    if(l != r && lazy[rt] != -1){
        lazy[rt<<1] = v; 
        lazy[rt<<1|1] = v;
        mem(cnt[rt<<1], 0);
        mem(cnt[rt<<1|1], 0);
        int m = (l + r) / 2;
        cnt[rt<<1][v] = m - l + 1;
        cnt[rt<<1|1][v] = r - m;
        lazy[rt] = -1;
    }
}
void update(int L, int R, int v, pdef){
    if(L <= l && r <= R){
        mem(cnt[rt], 0);
        cnt[rt][v] = r - l + 1;
        lazy[rt] = v;
        return;
    }
    int m = (l + r) / 2;
    pushdown(l, r, rt);
    if(L <= m) update(L, R, v, lson);
    if(m < R) update(L, R, v, rson);
    for(int i=0; i<26; ++i) cnt[rt][i] = cnt[rt<<1][i] + cnt[rt<<1|1][i];
}

int ans[26];
void query(int L, int R, pdef){
    if(L <= l && r <= R){
        for(int i=0; i<26; ++i) ans[i] += cnt[rt][i];
        return;
    }
    int m = (l + r) / 2;
    pushdown(l, r, rt);
    if(L <= m) query(L, R, lson);
    if(m < R) query(L, R, rson);
}
void print(pdef){
    if(l == r){
        putchar(lazy[rt] + 'a');
        return;
    }
    pushdown(l, r, rt);
    int m = (l + r) / 2;
    print(lson);
    print(rson);
}

char ch[N];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    int a, b, c, p;
    while(scanf("%d%d\n", &n, &m) != EOF){
        build(1, n, 1);
        for(int i=0; i<m; ++i){
            mem(ans, 0);
            scanf("%d%d", &a, &b);
            query(a, b, 1, n, 1);
            c = 0;
            for(int i=0; i<26; ++i) c += ans[i] % 2;
            if(c > 1) continue;
            p = -1;
            for(int i=0; i<26; ++i) if(ans[i] % 2) p = i;
            c = 0;
            if(p != -1) update((a+b)/2, (a+b)/2, p, 1, n, 1);
            for(int i=0; i<26; ++i){
                if(ans[i] < 2) continue;
                update(a+c, a+c+ans[i]/2-1, i, 1, n, 1);
                update(b-c-ans[i]/2+1, b-c, i, 1, n, 1);
                c += ans[i] / 2;
            }
        }
        print(1, n, 1);
        putchar(10);
    }
    return 0;
}