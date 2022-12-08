// 21:38
// 21:51 - 22:17 - re sample
//       - 22:21 - pause
// 22:3x - 22:45 - mle
#include <cassert>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=5, M=20;

struct State {
    int t, pre_s, pre_t;
    State() {}
    State(int x, int y, int z) : t(x), pre_s(y), pre_t(z) {}
    bool operator ==(const State &state) const {
        return t==state.t;
    }
    bool operator <(const State &state) const {
        return t<state.t;
    }
};

State pool[20000000]; int num;
int fs[M+1][1<<N], ft[M+1][1<<N];

int lab[1<<(N*4)];
int delta[1<<N][1<<N];
VI cols[N+1];
int a[N], b[M];
int n, m;

bool good_ending(int t) {
    repn(i, n) {
        int x=t&15; t>>=4;
        if(x!=a[i]) return false;
    }
    return t==0;
}

int main() {
    scanf("%d%d", &n,&m);
    repn(i, n) scanf("%d", &a[i]);
    repn(i, m) scanf("%d", &b[i]);

    repn(s, 1<<n) repn(s2, 1<<n) {
        int d=0;
        repn(i, n) if((s&(1<<i))==0 && (s2&(1<<i))>0) d|=(1<<(i*4));
        delta[s][s2]=d;
    }
    rep(i, 0, n) cols[i].clear();
    repn(s, 1<<n) {
        int cnt=0, la=0; 
        for(int x=s; x; x>>=1) {
            if(la==0 && (x&1)>0) ++cnt;
            la=(x&1);
        }
        cols[cnt].pb(s);
    }

    rep(i, 0, m) repn(s, 1<<n) fs[i][s]=ft[i][s]=0;
    fs[0][0]=0, ft[0][0]=1; num=1;
    pool[0]=State(0, -1, -1);

    fillchar(lab, 0); int lab_c=0;
    rep(i, 0, m-1) {
        //printf("i=%d\n",i);
        for(int s2: cols[b[i]]) {
            int le=num;
            repn(s, 1<<n) {
                rep(k, fs[i][s], ft[i][s]-1) {
                    int t=pool[k].t;
                    int t2=t+delta[s][s2];
                    //printf("  s=%d t=%d s2=%d t2=%d\n",s,t,s2,t2);
                    pool[num++]=State(t2, s, t);
                }
            }
            //*
            int num2=le;
            ++lab_c;
            rep(k, le, num-1) if(lab[pool[k].t]<lab_c) {
                pool[num2++]=pool[k];
                lab[pool[k].t]=lab_c;
            }
            num=num2;
            /*/
            sort(pool+le, pool+num);
            num=int(unique(pool+le, pool+num)-pool);
            //*/
            fs[i+1][s2]=le, ft[i+1][s2]=num;
        }
    }
    //printf("%d\n",num);
    /*
    rep(i, 0, m) {
        repn(s, 1<<n) {
            for(const State &cur: f[i][s]) {
                printf("i=%d s=%d t=%d\n", i, s, cur.t);
            }
        }
    }
    */


    int s0=-1, t0=-1;
    repn(s, 1<<n) rep(k, fs[m][s], ft[m][s]-1) {
        int t=pool[k].t;
        if(good_ending(t)) s0=s, t0=t;
    }
    assert(s0>=0 && t0>=0);
    //printf("s0=%d t0=%d\n",s0,t0);
    int ans[M];
    irepn(i, m) {
        ans[i]=s0;
        //printf("want: i=%d s0=%d t0=%d\n",i,s0,t0);
        //for(State state: f[i+1][s0]) printf("  [%d %d %d]",state.t,state.pre_s,state.pre_t);
        //printf("\n");
        int k=fs[i+1][s0]; while(pool[k].t!=t0) ++k;
        State state=pool[k];
        //int le=fs[i+1][s0], ri=ft[i+1][s0];
        //State state=*lower_bound(pool+le, pool+ri, State(t0,0,0));
        s0=state.pre_s;
        t0=state.pre_t;
    }
    repn(i, n) {
        repn(j, m) printf("%c", (ans[j]&(1<<i))?'*':'.');
        printf("\n");
    }
    //for(;;);

    return 0;
}