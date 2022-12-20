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

struct Suffix{
	int n;
	static const int LEN = 210001;
	int sa[LEN], r[LEN];//rsa[i]
    int best[20][LEN];
	int cmp(int *r, int a, int b, int l)
	{return r[a]==r[b]&&r[a+l]==r[b+l];}

	void getsa(int m){
		int i,j,p,*t,*x=best[0],*y=best[1], *wv=best[2], *ws=best[3];
		for(i=0;i<m;i++) ws[i]=0;
		for(i=0;i<=n;i++) ws[x[i]=r[i]]++;
		for(i=1;i<m;i++) ws[i]+=ws[i-1];
		for(i=n;i>=0;i--) sa[--ws[x[i]]]=i;
		for(j=1,p=1;p<=n;j*=2,m=p){
			for(p=0,i=n+1-j;i<=n;i++) y[p++]=i;
			for(i=0;i<=n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
			for(i=0;i<m;i++) ws[i]=0;
			for(i=0;i<=n;i++) ws[wv[i]=x[y[i]]]++;
			for(i=1;i<m;i++) ws[i]+=ws[i-1];
			for(i=n;i>=0;i--) sa[--ws[wv[i]]]=y[i];
			for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<=n;i++)
				//x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+j]==y[sa[i-1]+j])?p:++p;
				x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		}
	}
	int rank[LEN],height[LEN];
	void getheight(){
		int i,j,k=0;
		for(i=1;i<=n;i++) rank[sa[i]]=i; 
		for(i=0;i<n;height[rank[i++]]=k)
			for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
	}
	//int RMQ[LEN];
	int hbit[LEN];
	
	//inline int highbit(int a){
	//	__asm{
	//		BSR EAX, a
	//			MOV a, EAX
	//	}
	//	return a;
	//}
	void initRMQ(){
		int *RMQ = height;
		int i,j,a,b;
		for(hbit[0]=-1,i=1;i<=n;i++)
			hbit[i]=((i&(i-1))==0)?hbit[i-1]+1:hbit[i-1];
		for(i=1;i<=n;i++) best[0][i]=i;
		for(i=1;i<=hbit[n];i++){
			for(j=1;j<=n+1-(1<<i);j++){
				a=best[i-1][j];
				b=best[i-1][j+(1<<(i-1))];
				if(RMQ[a]<RMQ[b]) best[i][j]=a;
				else best[i][j]=b;
			}
		}
	}
	int askRMQ(int a,int b){
		int *RMQ = height;
		int t=hbit[b-a+1];
		b-=(1<<t)-1;
		a=best[t][a]; b=best[t][b];
		return RMQ[a]<RMQ[b]?a:b;
	}
	int lcp(int a, int b){
		int t;
		a=rank[a]; b=rank[b];
		if(a>b) swap(a, b);
		return height[askRMQ(a+1,b)];
	}
}suffix;

const int N = 210000;
char ch[N];
int nxt[N], pre[N], ind[N], last[N], a[N], org[N], wst[N];
lld ans[N];
int maxw[N], pas[N];
int main(){
    int n, k;
    int *r = suffix.r;
    while(scanf("%d%d", &n, &k) != EOF){
        int len = 0, temp;
        for(int i=1; i<=n; ++i){
            scanf("%s", ch);
            temp = strlen(ch);
            for(int j=0; j<temp; ++j){
                r[len] = ch[j] + n;
                last[len] = temp - j;
                org[len] = i;
                len ++;
            }
            r[len++] = i;
        }
        r[--len] = 0;
        suffix.n = len;
        suffix.getsa(len+1000);
        suffix.getheight();
        suffix.initRMQ();
        mem(a, 0xff), mem(pre, 0xff), mem(nxt, 0x3f);
        mem(wst, 0);
        for(int i=n; i<=len; ++i) ind[i] = org[suffix.sa[i]];
        for(int i=n; i<=len; ++i){
            pre[i] = a[ind[i]];
            if(pre[i] != -1) nxt[pre[i]] = i;
            a[ind[i]] = i;
        }
        int cnt = 0, l=n, r=n-1, w;
        while(l <= len){
            if(r < l) r = l, cnt = 1;
            while(cnt < k && r < len) if(pre[++r] < l) cnt ++;
            if(cnt < k) break;
            wst[l] = (l == r) ? last[suffix.sa[l]] : suffix.lcp(suffix.sa[l], suffix.sa[r]);
            if(nxt[l++] > r) cnt --;
        }
        mem(ans, 0);
        mem(maxw, 0);
        for(int i=n; i<=len; ++i){
            pas[i] = min(pas[i-1], suffix.height[i]);
            checkmax(pas[i], wst[i]);
            //if(pas[i]) cout << i << ' ' << ind[i] << ' ' << last[suffix.sa[i]] << ' ' << pas[i] << endl;
            ans[ind[i]] += pas[i];
        }
        for(int i=1; i<=n; ++i){
            cout << ans[i] << ' ';
        }
        puts("");
    }
    return 0;
}