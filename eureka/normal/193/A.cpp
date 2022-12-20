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
double eps=1e-8;//NOTES:eps
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

int h, w;
const int N = 60;
char mat[N][N];
int mark[N][N];
int vi[4] = {1, -1, 0, 0};
int vj[4] = {0, 0, 1, -1};

int cnt;
void dfs(int i, int j){
    if(mat[i][j] != '#') return;
    if(mark[i][j] == 1) return;
    mark[i][j] = 1;
    cnt ++;
    for(int k=0; k<4; ++k){
        dfs(i+vi[k], j+vj[k]);
    }
}

bool check(int i, int j, int tot){
    cnt = 0;
    mem(mark, 0);
    dfs(i, j);
    return cnt != tot;
}
int getbit(int n){
    int ans = 0;
    while(n){
        n &= n-1;
        ans ++;
    }
    return ans;
}

int num;
int fun(int i, int j, int ans){
    if(mat[i][j] != '#') return ans;
    int state = 0;
    for(int k=0; k<4; ++k){
        if(mat[i+vi[k]][j+vj[k]] == '#'){
            state |= 1 << k;
        }
    }
    for(int s=state;;s = (s-1) & state){
        int n = getbit(s);
        if(n < ans){
            for(int k=0; k<4; ++k){
                if(s & (1<<k)) mat[i+vi[k]][j+vj[k]] = '.';
            }
            if(check(i, j, num-n)) ans = n;
            for(int k=0; k<4; ++k){
                if(s & (1<<k)) mat[i+vi[k]][j+vj[k]] = '#';
            }
        }
        if(s == 0) break;
    }
    return ans;
}

int gao(){
    int ans = 10;
    num = 0;
    for(int i=1; i<=h; ++i){
        for(int j=1; j<=w; ++j){
            if(mat[i][j] == '#') num ++;
        }
    }
    for(int i=1; i<=h; ++i){
        for(int j=1; j<=w; ++j){
            checkmin(ans, fun(i, j, ans));
        }
    }
    if(ans > 4) ans = -1;
    return ans;
}

int main(){
    while(scanf("%d%d", &h, &w) != EOF){
        mem(mat, '.');
        for(int i=1; i<=h; ++i){
            scanf("%s", &mat[i][1]);
        }
        printf("%d\n", gao());
    }
    return 0;
}