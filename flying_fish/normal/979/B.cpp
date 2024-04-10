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
const LL maxn=5e5+7;
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

int C[3];
char A[maxn];
int cnt[256];
int main() {
    int i,j,n,k,T;
    scanf("%d",&n);
    REP(k,3){
        memset(cnt,0,sizeof(cnt));
        scanf("%s",A);
        int len=strlen(A);
        REP(i,len) cnt[A[i]]++;
        REP(i,255) if (('a'<=i&&i<='z')||('A'<=i&&i<='Z')){
            int remain=len-cnt[i];
            if (remain>=n) C[k]=max(C[k],cnt[i]+n);
            else{
                if (n==1&&remain==0) C[k]=max(C[k],len-1);
                else C[k]=max(C[k],len);
            }
        }
//        printf("%d\n",C[k]);
    }if (C[0]>C[1]&&C[0]>C[2]) puts("Kuro");
    else if (C[1]>C[0]&&C[1]>C[2]) puts("Shiro");
    else if (C[2]>C[0]&&C[2]>C[1]) puts("Katie");
    else puts("Draw");
}
/*
*/