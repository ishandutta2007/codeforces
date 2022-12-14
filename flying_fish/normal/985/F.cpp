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
const LL maxn=2e5+7;
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

int n,m;
char A[maxn];
LL F[maxn][27],G[maxn][27];
LL pw1[maxn],pw2[maxn];
vector<int> V1,V2;
int main() {
    int i,j;
    scanf("%d%d",&n,&m);
    scanf("%s",A+1);
    pw1[0]=pw2[0]=1;
    FOR(i,1,n) pw1[i]=pw1[i-1]*29%M;
    FOR(i,1,n) pw2[i]=pw2[i-1]*31%M;
    rFOR(i,1,n) {
        F[i][A[i]-'a']++; G[i][A[i]-'a']++;
        REP(j,26) (F[i][j]+=F[i+1][j]*29)%=M;
        REP(j,26) (G[i][j]+=G[i+1][j]*31)%=M;
    }REP(j,m){
        int x,y,len;int now=0,ans=0;
        scanf("%d%d%d",&x,&y,&len);
        V1.clear();V2.clear();
        REP(i,26) V1.push_back(((F[x][i]-pw1[len]*F[x+len][i])%M+M)%M);
        REP(i,26) V2.push_back(((F[y][i]-pw1[len]*F[y+len][i])%M+M)%M);
        sort(V1.begin(),V1.end());
        sort(V2.begin(),V2.end());
        REP(i,26) if (V1[i]!=V2[i]) ans=1;
        V1.clear();V2.clear();
        REP(i,26) V1.push_back(((G[x][i]-pw2[len]*G[x+len][i])%M+M)%M);
        REP(i,26) V2.push_back(((G[y][i]-pw2[len]*G[y+len][i])%M+M)%M);
        sort(V1.begin(),V1.end());
        sort(V2.begin(),V2.end());
        REP(i,26) if (V1[i]!=V2[i]) ans=1;
//        printf("%d : %d\n",j,ans);
        if (ans) puts("NO");
        else puts("YES");
    }
    return 0;
}
/*
*/