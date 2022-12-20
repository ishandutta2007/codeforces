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

const int N = 110000;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define pdef int l, int r, int rt=1
#define son lft, rgt, 1
struct SEG{
    int sum[N*4];
    void update(int p, int v, pdef){
        if(l == r){
            sum[rt] += v;
            return;
        }
        int m = (l + r) / 2;
        if(p <= m) update(p, v, lson);
        else update(p, v, rson);
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    }

    int query(int L, int R, pdef){
        if(L <= l && r <= R){
            return sum[rt];
        }
        int m = (l + r) / 2;
        int ans = 0;
        if(L <= m) ans += query(L, R, lson);
        if(R >= m+1) ans += query(L, R, rson);
        return ans;
    }
    void init(){
        mem(sum, 0);
    }
}sl, sr;
int a[N];
lld cal(lld n){
    return n*(n+1)/2;
}

int main(){
    int i;
    lld n, k;
    while(cin >> n >> k){
        int lft = 0, rgt = n+1;
        set<int> s;
        set<int>::iterator it;
        map<int, int> m;
        for(i=0; i<n; ++i){
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }
        a[n] = 1;
        for(it=s.begin(), i=1; it!=s.end(); ++it, ++i) m[*it] = i;
        for(i=0; i<n; ++i) a[i] = m[a[i]];

        lld inv = 0;
        sr.init(), sl.init();
        for(int i=n-1; i>=0; --i){
            inv += sr.query(lft, a[i]-1, lft, rgt, 1);
            sr.update(a[i], 1, lft, rgt, 1);
        }

        int l, r=0;
        lld suminv=inv, add;
        lld ans = 0;
        for(l=0; l<n; ++l){
            sl.update(a[l], 1, son);
            suminv += sr.query(lft, a[l]-1, son) + sl.query(a[l]+1, rgt, son);
            while((r < n && suminv > k) || l==r){
                suminv -= sr.query(lft, a[r]-1, son) + sl.query(a[r]+1, rgt, son);
                sr.update(a[r], -1, son);
                r ++;
            }
            ans += n-r;
        }
        cout << ans << endl;
    }
    return 0;
}