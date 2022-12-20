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
using namespace std;
const double pi=acos(-1.0);//NOTES:pi
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

const int N = 110000;
vector<pair<int, pair<int, int> > > in;
vector<pair<int, int> > query;
lld ans[N];
multiset<int> s;
void gao_union(){
    sort(in.begin(), in.end());
    for (int i=0; i<in.size(); ++i){
        if (i != 0 && !s.empty()){
            int t = *(s.begin());
            query.PB(MP(t - in[i-1].first, -1));
            query.PB(MP(t - in[i].first, 1));
        }
        if (in[i].second.second == 1){
            s.insert(in[i].second.first);
        }else {
            s.erase(s.find(in[i].second.first));
        }
    }
}

void gao(){
    sort(query.begin(), query.end());
    lld cnt = 0;
    lld sum = 0;
    lld w = 0;
    for (int i=0; i<query.size(); ++i){
        if (i) sum += (query[i].first - query[i-1].first) * w;
        w += query[i].second;
        if (query[i].second == 0){
            ans[cnt++] = sum;
        }
    }
}

int main(){
    int n, m;
    int a, b, c, d;
    cin >> m >> n;
    for (int i=0; i<n; ++i){
        scanf("%d%d%d", &a, &b, &c);
        in.PB(MP(a, MP(c, 1)));
        in.PB(MP(b, MP(c, -1)));
    }
    gao_union();
    for (int i=0; i<m; ++i){
        scanf("%d", &a);
        query.PB(MP(a, 0));
    }
    gao();
    for (int i=0; i<m; ++i){
        cout << ans[i] << endl;
    }
    return 0;
}