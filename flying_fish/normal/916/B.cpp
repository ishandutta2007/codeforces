#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <utility>
using namespace std;
#define REP(I,N) for (I=0;I<N;I++)
#define rREP(I,N) for (I=N-1;I>=0;I--)
#define rep(I,S,N) for (I=S;I<N;I++)
#define rrep(I,S,N) for (I=N-1;I>=S;I--)
#define FOR(I,S,N) for (I=S;I<=N;I++)
#define rFOR(I,S,N) for (I=N;I>=S;I--)
typedef unsigned long long ULL;
typedef long long LL;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e6+7;
const double eps=0.00000001;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<typename T>inline T powMM(T a,T b){T ret=1;for (;b;b>>=1ll,a=1ll*a*a%M) if (b&1) ret=1ll*ret*a%M;return ret;}

LL n;int m;
int f[maxn];
int t=0;
int k;
priority_queue<int> Q;
int cnt[1000];int MAX=-INF,MIN=INF;
const int MID=50;
int main(){
    int i,j;
    scanf("%I64d%d",&n,&m);
    while ((1ll<<t)<=n) t++;
    while (n){
        while ((1ll<<t)>n) t--;
        MAX=max(MAX,t+MID);MIN=min(MIN,t+MID);
        cnt[t+MID]++;n-=1ll<<t;
        m--;
    }if (m<0) return 0*puts("No");
    while (m>=cnt[MAX]){
        m-=cnt[MAX];
        cnt[MAX-1]+=cnt[MAX]*2;cnt[MAX]=0;
        MIN=min(MIN,MAX-1);
        MAX--;
    }cnt[MIN]--;m++;puts("Yes");
    rREP(i,1000) while (cnt[i]) printf("%d ",i-MID),cnt[i]--;
    MIN-=MID;
    while (m>1) printf("%d ",MIN-1),MIN--,m--;
    printf("%d",MIN);
}
/*
*/