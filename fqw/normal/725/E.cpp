#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int V=200010;

int main() {
    int c, n; scanf("%d%d", &c,&n);
    VI cnt(V);
    repn(i, n) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    VI next(V);
    repn(i, V) {
        if(cnt[i]>0) {
            next[i]=i;
        } else if(i>0) {
            next[i]=next[i-1];
        }
    }

    rep(new_coin, 1, c) {
        int r=c, rbound=c;
        while(r>0) {
            int x=0, num=0;
            if(next[rbound]>0) {
                x=next[rbound];
                num=cnt[x];
            }
            if(new_coin==x) {
                ++num;
            } else if(new_coin>x && new_coin<=rbound) {
                x=new_coin;
                num=1;
            }
            if(x==0) {
                break;
            }
            setmin(num, r/x);
            r-=num*x;
            rbound=min(r, x-1);
        }
        if(r>0) {
            printf("%d\n", new_coin);
            return 0;
        }
    }
    printf("Greed is good\n");

    return 0;
}