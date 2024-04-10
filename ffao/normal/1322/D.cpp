#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


using namespace std;


#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(long long x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


typedef long long ll;


#define all(v) (v).begin(), (v).end()


typedef long long ll;

ll pd[2100][2100];
ll pd2[2100][2100];
int agggg[2100];
int cost[2100];
int value[4100];

int first[2100][2100];
int seen[2100][2100];

int n, m;

ll rec2(int pos, int min_agg);

ll rec(int pos, int hm) {
    //printf("%d %d\n",pos,hm);
    if (pos == -1) return 0;

    int ohm = hm;
    ll &ret = pd[pos][hm];

    if (!seen[pos][hm]) {
        seen[pos][hm] = 1;
        ret = -1000000000000000000LL;
        
        int cur_agg = agggg[pos];
        ll cur_cost = 0;

        while (1) {
            if (hm == 0) {
                ret = max(ret, cur_cost + rec2(pos-1, cur_agg));
                break;
            }

            int next_pos = (pos == 0 ? -1 : first[cur_agg][pos-1]);
            if (next_pos != -1) ret = max(ret, cur_cost + rec(next_pos, hm));
            if (next_pos != -1) ret = max(ret, cur_cost + value[cur_agg] - cost[next_pos] + rec(next_pos, hm+1));

            hm /= 2;
            cur_agg++;
            cur_cost += hm * 1ll * value[cur_agg];
        }
    }

    //printf("rec %d %d -> %lld\n", pos,ohm,ret);
    return ret;
}

ll rec2(int pos, int min_agg) {
    if (pos == -1 || min_agg > m) return 0;

    ll &ret = pd2[pos][min_agg];
    if (ret == -1) {
        ret = rec2(pos-1, min_agg);
        if (agggg[pos] >= min_agg) ret = max(ret, value[agggg[pos]] - cost[pos] + rec(pos, 1));
    }
    return ret;
}


void solve()
{
    memset(pd2,-1,sizeof(pd2));

    re(n,m);
    for (int i = 0; i < n; i++) {
        re(agggg[i]);
    }
    agggg[n] = 0;

    for (int i = 0; i < n; i++) re(cost[i]);
    for (int i = 1; i <= n+m; i++) re(value[i]);

    for (int a = m+50; a >=0; a--) {
        first[a][0] = (agggg[0] == a) ? 0 : -1;
        for (int i = 1; i <= n; i++) first[a][i] = (agggg[i] == a ? i : first[a][i-1]);
    }

    ll ans = rec2(n-1,0);
    ps(ans);
}


int main() {


    solve();
}


 // and triples


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


void pr(long long x) { printf("%lld", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}


#include <array>