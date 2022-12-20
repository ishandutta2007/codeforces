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
#define lowbits(a, n) ((a) & (shl(n)-1))
const int N = 130, M = 7;
const lld P = 1000000007;
int cnt[N];
int n, m, t;
int mod[N*3];
struct BIT{
    llu a[2];
};

int len, l;
llu temp;
BIT move(const BIT &a, int i){
    BIT ans;
    if(i < 0) i += m;
    if(m <= 64){
        ans.a[0] = a.a[0] >> i;
        ans.a[0] |= lowbits(a.a[0], i) << (m-i);
    }else{
        if(i <= m-64){
            ans.a[0] = a.a[0] >> i;
            ans.a[1] = a.a[1] >> i;
            ans.a[0] |= lowbits(a.a[1], i) << (64 - i);
            ans.a[1] |= lowbits(a.a[0], i) << (m-64 - i);
        }else if(i >= 64){
            i = m - i;
            ans.a[0] = a.a[0] << i;
            ans.a[1] = lowbits(a.a[1] << i, m-64);
            ans.a[0] |= a.a[1] >> (m-64-i);
            ans.a[1] |= a.a[0] >> (64-i);
        }else{
            temp = lowbits(a.a[0], i);
            ans.a[0] = a.a[0] >> i;
            ans.a[0] |= a.a[1] << (64 - i);
            ans.a[1] = temp >> (i - m + 64);
            ans.a[0] |= lowbits(temp, i-m+64) << (64 - i + (m - 64));
        }
    }
    return ans;
}

void huo(BIT &a, const BIT &b){
    a.a[0] |= b.a[0];
    a.a[1] |= b.a[1];
}

void print(int deep){
    while(deep --){
        printf("  ");
    }
}
BIT table[M];
lld gao(int deep, int begin, lld way){
    lld ans = 1, temp;
    if(deep < 7){
        for(int i=begin; i<m; ++i){
            if(cnt[i] == 0 || (table[deep].a[0] & shl(i))) continue;
            table[deep+1].a[0] = table[deep].a[0];
            table[deep+1].a[1] = table[deep].a[1];
            huo(table[deep+1], move(table[deep], i));
            huo(table[deep+1], move(table[deep], -i));
            temp = gao(deep+1, i+1, cnt[i]);
            ans += temp;
        }
    }
    ans %= P;
    return ans * way % P;
}

void print(BIT d){
    printf("%llx %llx\n", d.a[0], d.a[1]);

}
int main(){
    while(scanf("%d%d%d", &n, &m, &t) != EOF){
        mem(cnt, 0);
        int a;
        for(int i=0; i<t; ++i){
            scanf("%d", &a);
            a %= m;
            cnt[min(a, m-a)] ++;
        }
        table[0].a[0] = 1;
        table[0].a[1] = 0;
        cout << gao(0, 0, 1) << endl;
    }
    return 0;
}