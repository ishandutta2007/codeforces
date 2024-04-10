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
int ans;
char a[maxn];
int d[maxn];
vector<int> edge[maxn];
int have[maxn][27];
bool mark[maxn];
queue<int> Q;
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",a+1);
    FOR(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);d[v]++;
    }
    FOR(i,1,n) if (d[i]==0) Q.push(i);
    while (Q.size()){
        int u=Q.front();Q.pop();
        have[u][a[u]-'a']++;mark[u]=1;
//        printf("%d : %c ",u,a[u]);REP(i,26) printf("%d ",have[u][i]);puts("");
        REP(i,26) ans=max(ans,have[u][i]);
        for (int v:edge[u]){
            REP(i,26) have[v][i]=max(have[v][i],have[u][i]);
            d[v]--;
            if (d[v]==0) Q.push(v);
        }
    }
    FOR(i,1,n) if (!mark[i]) return 0*puts("-1");
    printf("%d\n",ans);
}
/*
*/