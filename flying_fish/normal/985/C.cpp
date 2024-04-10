#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <utility>
#include <cassert>
#include <bitset>
using namespace std;
#define REP(I,N) for (I=0;I<N;I++)
#define rREP(I,N) for (I=N-1;I>=0;I--)
#define rep(I,S,N) for (I=S;I<N;I++)
#define rrep(I,S,N) for (I=N-1;I>=S;I--)
#define FOR(I,S,N) for (I=S;I<=N;I++)
#define rFOR(I,S,N) for (I=N;I>=S;I--)
#define dbg(x) cerr <<#x<<" = "<<x<<" ;  "
#define dbgln(x) cerr <<#x<<" = "<<x<<endl
typedef unsigned long long ULL;
typedef long long LL;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e5+7;
const double pi=acos(-1.0);
const double eps=0.00000001;
LL gcd(LL a, LL b) {return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<typename T>inline T powMM(T a, T b) {
    T ret=1;
    for (; b; b>>=1ll,a=(LL)a*a%M)
        if (b&1) ret=(LL)ret*a%M;
    return ret;
}

int n,m,k,l;
int A[maxn];
LL ans;
priority_queue<int> Q;
int main() {
    int i;
    scanf("%d%d%d",&n,&k,&l);
    m=n*k;
    FOR(i,1,n*k) scanf("%d",&A[i]);
    sort(A+1,A+1+m);
    FOR(i,1,m){
        if (A[i]-A[1]>l) break;
//        printf("%d ",A[i]);
        if (i%k==1){
            ans+=A[i];
            n--;
        }else Q.push(-A[i]);
        while (Q.size()>n) Q.pop();
    }while (n){
        if (!Q.size()) return 0*puts("0");
        ans-=Q.top();Q.pop();n--;
    }printf("%I64d\n",ans);
    return 0;
}
/*
*/