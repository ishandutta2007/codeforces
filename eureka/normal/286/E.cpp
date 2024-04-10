#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <complex>
using namespace std;
typedef long long lld;
typedef unsigned long long llu;
const int intmax=0x3f3f3f3f;//NOTES:intmax
const lld lldmax=0x3f3f3f3f3f3f3f3fll;//NOTES:lldmax
double eps=1e-8;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclid(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclid(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclid(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline int dblcmp(T a,const T b){a-=b; return a>eps?1:(a<-eps?-1:0);}//NOTES:doublecmp
template<class T> inline int sgn(T a){return a>eps?1:(a<-eps?-1:0);}
#define mem(a, val) memset(a, val, sizeof(a))//memset(
#define shl(i)      ((lld)1 << (i))
#define MP make_pair
#define PB push_back
#define cp complex<double>

void print(cp a, char ch){
    printf("%.2lf %.2lf%c", a.real(), a.imag(), ch);
}
const int MAXN = 1 << 21;
const cp I = cp(0, 1);

void fft(cp A[], cp B[], bool inv = false){
    int N = MAXN;
    double arg = M_PI;
    for (int n=N/2; n>=1; n/=2){
        cp pow = cp(1, 0);
        cp mul = exp((inv ? 1.0 : -1.0) * I * arg);
        for (int j=0; j<N; j+=n){
            for (int i=0; i<n; ++i){
                B[i+j] = A[i+j*2%N] + A[i+n+j*2%N] * pow;
            }
            pow = pow * mul;
        }
        for (int i=0; i<N; ++i) A[i] = B[i];
        arg /= 2.0;
    }
}

cp a[MAXN], b[MAXN], c[MAXN], d[MAXN];

bool judge(int m){
    for (int i=0; i<=m; ++i){
        if (c[i].real() > 0.5 && a[i].real() < 0.5) return false;
    }
    return true;
}
int main(){
    int n, m;
    int tmp;
    cin >> n >> m;
    for (int i=0; i<n; ++i){
        scanf("%d", &tmp);
        a[tmp] = b[tmp] = 1;
    }
    fft(b, d);
    for (int i=0; i<MAXN; ++i) c[i] = b[i] * b[i];
    fft(c, d, true);
    for (int i=0; i<MAXN; ++i) c[i] = c[i] * (1.0 / MAXN);
    if (judge(m)){
        puts("YES");
        int cnt = 0;
        for (int i=0; i<=m; ++i){
            if (a[i].real() > 0.5 && c[i].real() < 0.5) cnt ++;
        }
        printf("%d\n", cnt);
        for (int i=0; i<=m; ++i){
            if (a[i].real() > 0.5 && c[i].real() < 0.5) printf("%d ", i);
        }
        puts("");
    }else {
        puts("NO");
    }
    return 0;
}