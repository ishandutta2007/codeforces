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
using namespace std;
typedef double real;
const real pi=acos(-1.0);//NOTES:pi
typedef long long lld;
typedef unsigned long long llu;
const int intmax=0x3f3f3f3f;//NOTES:intmax
//const lld lldmax=0x3f3f3f3f3f3f3f3fll;//NOTES:lldmax
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
#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define shl(i)      ((lld)1 << (i))
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

int best, n3, n4, n5, b3, b4, b5;
int s;
void check(int c3, int c4, int c5){
    if(0 <= c3 && c3 <= c4 && c4 <= c5 && n3*c3+n4*c4+n5*c5==s){
        int temp = abs(c3*n3 - c4*n4) + abs(c4*n4 - c5*n5);
        if(temp < best){
            best = temp;
            b3 = c3, b4 = c4, b5 = c5;
        }
    }
}

void check3(int c3, int c4){
    check(c3, c4, (s-n3*c3-n4*c4)/n5);
}

void check5(int c4, int c5){
    check((s-n4*c4-n5*c5)/n3, c4, c5);
}

int go(int a, int step, int up){
    int n = (up - a) / step;
    return a + n * step;
}

int main(){
    int n;
    int temp;
    while(scanf("%d%d", &n, &s) != EOF){
        n3 = n4 = n5 = 0;
        for(int i=0; i<n; ++i){
            scanf("%d", &temp);
            if(temp == 3) n3 ++;
            if(temp == 4) n4 ++;
            if(temp == 5) n5 ++;
        }
        best = intmax;
        int sum;
        int x, y;
        int g = euclid(n3, n5, x, y);
        int s3 = n3 / g, s5 = n5 / g;
        x = checkmod(x, n5/g);
        y = checkmod(y, n3/g);
        for(int i=0; i*(n4+n5) <= s; ++i){
            sum = s - i*n4;
            if(sum % g) continue;
            int sx = checkmod(sum/g*x, n5/g);
            int sy = checkmod(sum/g*y, n3/g);
            check3(sx, i);
            check3(go(sx, s5, i), i);
            check3(go(sx, s5, i)+s5, i);
            check3(go(sx, s5, sum)+s5, i);
            check3(go(sx, s5, sum), i);
            check3(go(sx, s5, i*n4/n3), i);
            check3(go(sx, s5, i*n4/n3)+s5, i);
            check5(i, sy);
            check5(i, go(sy, s3, i));
            check5(i, go(sy, s3, i)+s3);
            check5(i, go(sy, s3, sum));
            check5(i, go(sy, s3, sum)+s3);
            check5(i, go(sy, s3, i*n4/n5));
            check5(i, go(sy, s3, i*n4/n5)+s3);
        }
        if(best == intmax) puts("-1");
        else printf("%d %d %d\n", b3, b4, b5);
    }
    return 0;
}