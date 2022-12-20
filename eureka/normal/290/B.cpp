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
#define ff(i, n) for(int i=0; i<n; ++i)

string a = "111111101010101111100101001111111100000100000000001010110001000001101110100110110000011010001011101101110101011001001111101001011101101110101100011000111100101011101100000101010101011010000101000001111111101010101010101010101111111000000001111101111100111100000000100010111100100001011110111111001110111001111111100100001000101100011100111010000101000111010001010011110000110001111110101100000011111111111111111000111001001011000111000010111010011010011010100100101010100010110010110101010000010101100000101010001111101000000000000010100011001101000111101011010101001001111101111000101010001110101101111111000100100001110001000000010011000100110000011010000010001101101001101110010010011011000011101011010001000111101010100110111010100110011101001101000001110110001010010101111000101111111000001000111011100001010110111110000000000001110010110100010100010110111111101000101111000110101011010100000100111010101111100100011011101110101001010000101000111111000101110100011010010010111111011010101110100100011011110110101110000100000100110011001111100111100000111111101101000101001101110010001";
int main()
{
    int i, j;
    cin >> i >> j;
    cout << a[i*33+j] << endl;
}