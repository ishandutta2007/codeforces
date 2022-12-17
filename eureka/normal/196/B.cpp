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
const double pi=acos(-1.0);//NOTES:pi
typedef long long i64;
typedef unsigned long long u64;
const int intmax=0x3f3f3f3f;//NOTES:intmax
//const i64 i64max=0x3f3f3f3f3f3f3f3fi64;//NOTES:i64max
double eps=1e-6;//NOTES:eps
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
    double x, y;
    vec2(double x, double y):x(x), y(y){}
    vec2 operator+(const vec2 &b)const{ return vec2(x+b.x, y+b.y);}
    vec2 operator-(const vec2 &b)const{ return vec2(x-b.x, y-b.y);}
    vec2 operator*(const double &b)const{ return vec2(x*b, y*b);}
    vec2 operator/(const double &b)const{ return vec2(x/b, y/b);}
};

const int N = 1510;
char mat[N][N], mark[N][N];
int x[N][N], y[N][N];
int h, w;
bool flag;
int si, sj;
void dfs(int i, int j){
    if(flag) return;
    int ai = checkmod(i, h), aj = checkmod(j, w);
    int bi = (i-ai) / h, bj = (j-aj) / w;
    if(mat[ai][aj] == '#') return;
    if(mark[ai][aj] == 1){
        if(x[ai][aj] != bi || y[ai][aj] != bj) flag = true;
        return;
    }
    mark[ai][aj] = 1;
    x[ai][aj] = bi;
    y[ai][aj] = bj;
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

void find(){
    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            if(mat[i][j] == 'S'){
                si = i;
                sj = j;
                return;
            }
        }
    }
}
bool gao(){
    mem(mark, 0);
    find();
    flag = false;
    dfs(si, sj);
    return flag;
}

int main(){
    while(scanf("%d%d", &h, &w) != EOF){
        getchar();
        for(int i=0; i<h; ++i){
            gets(mat[i]);
        }
        if(gao()) puts("Yes");
        else puts("No");
    }
    return 0;
}