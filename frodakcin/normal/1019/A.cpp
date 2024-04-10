#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

const int MAXN = 3030;
const int MAXM = 3030;
const ll INF = 1e18;

int N, M;
int v[MAXM];
vi p[MAXM];
vl ps[MAXM];
struct Vote {
public:
    int pt;     //party
    int pr;     //price
    int pn;     //party num
    
    bool operator < (const Vote& o) {
        return pr < o.pr;
    }
    bool operator > (const Vote& o) {
        return pr > o.pr;
    }
    Vote() {pt = pr = pn = -1;}
    Vote(int a, int b, int c) {
        pt = a;
        pr = b;
        pn = c;
    }
} av[MAXM];
int avctr;

int orig;
int buy[MAXM];
ll getPrice(int n) {
    if(n <= 0 or n > N) return INF;
    
    int og = orig;
    ll ret = 0;
    for(int i = 2;i <= M;i++) buy[i] = 0;
    for(int i = 2;i <= M;i++) {
        if(v[i] >= n) {
            buy[i] = v[i] - n + 1;
            ret += ps[i][buy[i]];
            og += buy[i];
        }
    }
    
    if(og >= n) return ret;
    for(int i = 0;i < avctr;i++) {
        if(og >= n) return ret;
        if(buy[av[i].pt] < av[i].pn) {
            og++;
            ret += av[i].pr;
        }
    }
    return INF;
}

int main() {
    scanf("%d%d", &N, &M);
    
    for(int i = 0;i < N;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        p[a].pb(b);
    }
    orig = p[1].size();
    
    avctr = 0;
    for(int i = 2;i <= M;i++) {
        if(p[i].size() == 0) continue;
        sort(p[i].begin(), p[i].end());
        ps[i].pb(0);
        for(int j = 0;j < p[i].size();j++) ps[i].pb(ps[i][j] + p[i][j]);
        for(int j = 0;j < p[i].size();j++) av[avctr++] = Vote(i, p[i][j], j + 1);
        v[i] = p[i].size();
    }
    if(avctr > 1) sort(av, av + avctr, [](Vote& a, Vote& b){return a < b;});
    
    
    ll ans = INF, ta;
    for(int i = 1;i <= N;i++) {
        if((ta = getPrice(i)) < ans) ans = ta;
    }
    printf("%lld\n", ans);
    
    return 0;
}