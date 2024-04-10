#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#define _ (int)
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define pb push_back
#define mp std::make_pair
typedef long long LL;
typedef unsigned long long ULL;
typedef std::pair<LL,LL> PLL;
typedef std::pair<int,int> PII;
typedef std::pair<double,double> PDD;
typedef std::vector<LL> VL;
typedef std::vector<int> VI;
typedef std::vector<PII> VPI;
typedef std::vector<std::string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

int a[100010], pos[1010], nxt[1010];
int n, num;

int main() {
    scanf("%d", &n); num=0;
    auto is_lucky=[](int x) {
        while(x>0) {
            if(x%10!=4 && x%10!=7) return false;
            x/=10;
        }
        return true;
    };
    rep(i, 1, n) {
        scanf("%d", &a[i]);
        if(is_lucky(a[i])) pos[++num]=i;
    }
    pos[0]=0, pos[num+1]=n+1;
    rep(i, 1, num) {
        nxt[i]=num+1;
        rep(j, i+1, num) if(a[pos[i]]==a[pos[j]]) {
            nxt[i]=j; break;
        }
    }

    ULL ans=ULL(n+2)*ULL(n+1)*ULL(n)/6*ULL(n-1)/4;
    rep(i, 1, num) {
        // r1 in [pos[i], pos[i+1])
        LL cur=0, K=pos[i+1]-pos[i];
        std::set<int> s({pos[i], n+1});
        irep(j, i, 1) {
            // l1 in (pos[j-1], pos[j]]
            if(nxt[j]>i) {
                for(int k=nxt[j]; k<=num; k=nxt[k]) {
                    auto x=s.insert(pos[k]).fi, y=x;
                    --x, ++y;
                    if(x==s.begin()) {
                        cur+=(K*(K+1)/2+LL(pos[k]-pos[i+1])*K)*(*y-pos[k]);
                    } else {
                        cur+=K*(pos[k]-*x)*(*y-pos[k]);
                    }
                }
            }
            ans-=cur*LL(pos[j]-pos[j-1]);
        }
    }
    std::cout<<ans<<std::endl;

    return 0;
}