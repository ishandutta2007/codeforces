#include <sstream>
#include <fstream>
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
 
#define DEBUG
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define deputs(str) fprintf(stderr, "%s\n",str)
#else
#define debug(...)
#define deputs(str)
#endif // DEBUG
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long LL;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e6+107;
const double pi=acos(-1.0);
const double eps=0.0000000001;
LL gcd(LL a, LL b) {return b?gcd(b,a%b):a;}
template<typename T>inline void pr2(T x,int k=64) {ll i; REP(i,k) debug("%d",(x>>i)&1); putchar(' ');}
template<typename T>inline void add_(T &A,int B,ll MOD=M) {A+=B; (A>=MOD) &&(A-=MOD);}
template<typename T>inline void mul_(T &A,ll B,ll MOD=M) {A=(A*B)%MOD;}
template<typename T>inline void mod_(T &A,ll MOD=M) {A%=MOD; A+=MOD; A%=MOD;}
template<typename T>inline void max_(T &A,T B) {(A<B) &&(A=B);}
template<typename T>inline void min_(T &A,T B) {(A>B) &&(A=B);}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
inline ll powMM(ll a, ll b, ll mod=M) {
    ll ret=1;
    for (; b; b>>=1ll,a=a*a%mod)
        if (b&1) ret=ret*a%mod;
    return ret;
}
int startTime;
void startTimer() {startTime=clock();}
void printTimer() {debug("/--- Time: %ld milliseconds ---/\n",clock()-startTime);}

vector<int> Q[maxn];
priority_queue<pair<int,int> > P;
int A[maxn];
int out[maxn];
int main() {
    int _T,_; _T=1;
    scanf("%d",&_T);
    FOR(_,1,_T){
        int i; int n; int x,y;
        scanf("%d%d%d",&n,&x,&y); y-=x; int Y=y;
        FOR(i,1,n) {
            scanf("%d",&A[i]);
            Q[A[i]].push_back(i);
        } int none=0;
        FOR(i,1,n) out[i]=0;
        FOR(i,1,n+1) {
            if (Q[i].size()) P.push(make_pair(Q[i].size(),i));
            else none=i;
        }//none: not choose
        int same=x,notexist=n-y-x;
        while (P.size()&&same) {
            pii now=P.top(); P.pop();
            int p=now.second; int pos=*Q[p].rbegin();
            // printf("solve: val=%d pos=%d; cnt=%d %d\n",p,pos,same,notexist);
            if (same) {
                out[pos]=A[pos];
                Q[p].pop_back();
                if (Q[p].size()) P.push(make_pair(Q[p].size(),p));
                same--;
            }
        }
        //choose remove
        while (P.size()>1&&Y) {
            pii u=P.top(); P.pop(); int x=u.second; int px=*Q[x].rbegin();
            pii v=P.top(); P.pop(); int y=v.second; int py=*Q[y].rbegin();
            if (Y) out[px]=A[py],Y--;
            else out[px]=none,notexist--;
            Q[x].pop_back();
            if (Q[x].size()) P.push(make_pair(Q[x].size(),x));
            out[py]=A[px]; Q[y].pop_back();
            if (Q[y].size()) P.push(make_pair(Q[y].size(),y));
            if (Y) out[px]=A[py],Y--;
            else out[px]=none,notexist--;
        }
        if (P.size()==1&&Y) {//pop p
            pii u=P.top(); P.pop(); int x=u.second; int px=*Q[x].rbegin();
            FOR(i,1,n) if (Y&&out[i]!=A[i]&&out[i]&&out[i]!=x&&A[i]!=x) {
                Y--; Q[x].pop_back();
                if (Q[x].size()) P.push(make_pair(Q[x].size(),x));
                out[px]=out[i]; out[i]=x;
                break;
            }
        }
        // FOR(i,1,n) printf("%d%c",out[i]," \n"[i==n]); puts("<- first");
        // puts("first done");
        // FOR(i,1,n) printf("%d%c",out[i]," \n"[i==n]); puts("<- same");
        if (!Y) {
            while (P.size()&&notexist) {
                pii now=P.top(); P.pop();
                int p=now.second; int pos=*Q[p].rbegin();
                // printf("solve: val=%d pos=%d; cnt=%d %d\n",p,pos,same,notexist);
                if (notexist) {
                    out[pos]=none;
                    Q[p].pop_back();
                    if (Q[p].size()) P.push(make_pair(Q[p].size(),p));
                    notexist--;
                }
            }
            assert(Y==0&&!P.size()&&same==0&&notexist==0);
            // puts("second done");
            // FOR(i,1,n) printf("%d%c",out[i]," \n"[i==n]); puts("<- first");
            puts("YES");
            FOR(i,1,n) printf("%d%c",out[i]," \n"[i==n]);
        } else puts("NO");
        while (P.size()) P.pop();
        FOR(i,1,n+1) Q[i].clear();
    }

}
/*
100
5 2 4
3 1 1 2 5
5 3 4
1 1 2 1 2
4 0 4
5 5 3 3
4 1 4
2 3 2 3
6 1 2
3 2 1 1 1 1
6 2 4
3 3 2 1 1 1
6 2 6
1 1 3 2 1 1
1 0 0
1
1 0 1
1
1 1 1
1
9 1 5
1 1 1 1 1 1 1 1 1

1000
5 0 5
1 1 2 2 3
5 0 3
1 1 2 2 3

*/