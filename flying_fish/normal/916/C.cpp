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

int n,m;
int all=19260817;
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    if (n==2){
        printf("2 2\n");
        printf("1 2 2\n");
        return 0;
    }else{
        printf("2 %d\n",all);
        printf("1 %d 2\n",n),m--;all-=2;
        FOR(i,2,n-2)
            printf("1 %d 1\n",i),m--,all--;
        printf("1 %d %d\n",n-1,all),m--;
        FOR(i,2,n)
            FOR(j,i+1,n)
                if (m) printf("%d %d %d\n",i,j,19260817),m--;
                else break;
    }
}
/*
*/