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

int nxt[maxn*62][2],tot;
int cnt[maxn*62];
LL xornum,limit;
void Ins(int &now,int k,int val){
    if (!now) now=++tot;
    cnt[now]+=val;
    if (k==-1) return;
//    printf("Ins(%-2d):%d %d %d\n",xornum,now,k,val);
    int c=(xornum>>k)&1;
    Ins(nxt[now][c],k-1,val);
}
LL Que(int now,int k,bool mark){//mark:have limit
//    printf("que:%d(%d) %d %d\n",now,cnt[now],k,mark);
    if (!now||!cnt[now]) return -INFF;
    if (k==-1) return 0;
    int c=(xornum>>k)&1,lim=(limit>>k)&1;
    LL ret=-INFF;
    if (!lim&&mark){
        return Que(nxt[now][c],k-1,mark);
    }else {
//        ret=(1<<k)+Que(nxt[now][c^1],k-1,mark&&!(c&1));
//        if (ret<0) ret=Que(nxt[now][c],k-1,mark&&(c&1));
        ret=(1ll<<k)+Que(nxt[now][c^1],k-1,mark);
        if (ret<0) ret=Que(nxt[now][c],k-1,0);
    }return ret;
}
int root;
vector<LL> ans;
LL MAX;
int main() {
    int i,j,k,T;
    int n;
    scanf("%d",&n);
    FOR(i,1,n){
        LL k;
        scanf("%I64d",&k);
        xornum=k;
        Ins(root,61,1);
        MAX^=k;
    }while (1){
        xornum=MAX;limit=MAX-1;
        if (limit<0) break;
        LL nxt=Que(root,61,1);
//        printf("%I64d -> %I64d\n",nxt,MAX);
        if (nxt<0) break;
        ans.push_back(nxt^MAX);
        xornum=nxt^MAX;
        Ins(root,61,-1);
        MAX=nxt;
    }if ((int)ans.size()<n) return 0*puts("No");
    puts("Yes");
    reverse(ans.begin(),ans.end());
    for (LL v:ans) printf("%I64d ",v);

//    MAX=0;puts("");
//    for (int v:ans) MAX^=v,printf("%d ",MAX);
}
/*
*/