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
#include <bitset>
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

int n,m,k;
int i,j;
char c[2007][2007];
int ans;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    REP(i,n) scanf("%s",c[i]);
    if (k==1){
        REP(i,n) REP(j,m) if (c[i][j]=='.') ans++;
        printf("%d\n",ans);
    }else{
        REP(i,n){
            int t=0;
            REP(j,m){
                if (c[i][j]=='.') t++;
                else t=0;
//                printf("%d %d %d %d\n",i,j,k,t);
                if (t>=k) ans++;
            }
        }
        REP(j,m){
            int t=0;
            REP(i,n){
                if (c[i][j]=='.') t++;
                else t=0;
                if (t>=k) ans++;
            }
        }
        printf("%d\n",ans);
    }
}
/*
3 3 1
.*.
*.*
.*.
*/