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

int nxt[maxn*20*10][2],tot;
int num,limit;
void Ins(int now,int k){
    if (k==-1) return;
    int c=(num>>k)&1;
    if (!nxt[now][c]) nxt[now][c]=++tot;
    Ins(nxt[now][c],k-1);
}
int Que(int now,int k,bool mark){//mark:have limit
    if (!now) return -INF;
    if (k==-1) return 0;
    int c=(num>>k)&1,lim=(limit>>k)&1;
    int ret=-INF;
    if (!lim&&mark){
        return (c<<k)+Que(nxt[now][0],k-1,mark);
    }else {
        ret=(1<<k)+Que(nxt[now][c^1],k-1,mark&&!(c&1));
        if (ret<0) ret=Que(nxt[now][c],k-1,mark&&(c&1));
    }return ret;
}
vector<int> pre[maxn];
bool mark[maxn];
int main() {
    int i,j,T;
    FOR(i,1,100000){
        for (j=i;j<=100000;j+=i)
            pre[j].push_back(i);
    }int n;
    scanf("%d",&n);
    tot=100000;
    FOR(i,1,n){
        int op;
        int x,k,s;
        scanf("%d",&op);
        if (op==1){
            scanf("%d",&x);
            if (mark[x]) continue;
            num=x;
            for (int v:pre[x]) Ins(v,20);
            mark[x]=1;
        }else{
            scanf("%d%d%d",&x,&k,&s);
            if (x%k!=0||s-x<0){
//                printf("%d %d\n",x%k,s-x);
                puts("-1");
                continue;
            }num=x;limit=s-x;
            int ans=Que(k,20,1);
            if (ans<0) puts("-1");
            else printf("%d\n",ans^x);
        }
    }
}
/*
10
1 9
2 9 9 22
2 3 3 18
1 25
2 9 9 20

2 25 25 14
1 20
2 26 26 3
1 14
2 20 20 9

*/