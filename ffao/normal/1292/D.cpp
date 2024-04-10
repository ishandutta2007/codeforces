#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

void re(int& x);

void pr(long long x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef pair<int, int> pii;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int k[5100];
int p[5100];

int cost[5100][5100];
int n;

int g(int n, int p) {
    int r = 0;
    while (n) {
        r += n/p;
        n /= p;
    }
    return r;
}

int cnt = 0;
long long split(vector< pii >& who, int pr) {
    cnt++;

    while (p[pr]) pr--;
    if (sz(who) == 1) return 0;
    if (pr == 1) return 0;//5000) return 0;

    int all_cnt = 0;
    vector< pair<int, vector<pii>> > splits;
    
    long long tot_cost = 0;
    
    for (pii t : who) {
        int x = t.first;
        int c = g(x,pr);
        if (splits.empty() || c != splits.back().first) splits.push_back({c, {}});
        splits.back().second.push_back(t);
        //splits[g(x,pr)].push_back(t);
        tot_cost += cost[x][pr-1] * 1ll * t.second;
        all_cnt += t.second;
    }
    reverse(all(splits));

    vector<long long> totcst, totcnt = {0}, totp = {0};
    for (auto &p : splits) {
        long long this_cnt = 0, this_p = 0, this_cost = 0;
        for (pii t : p.second) {
            this_cnt += t.second;
            this_p += p.first * 1ll * t.second;
            this_cost += cost[t.first][pr-1] * 1ll * t.second;
        }
        totcnt.push_back(totcnt.back() + this_cnt);
        totp.push_back(totp.back() + this_p);
        totcst.push_back(this_cost);
    }

    long long ret = 1000000000000000000LL;
    int i = 0;
    for (auto &p : splits) {
        int this_cnt = 0;
        for (pii t : p.second) this_cnt += t.second;
        if (p.second.back().first == 1) p.second.back().second += all_cnt - this_cnt;
        else p.second.push_back({1, all_cnt - this_cnt});

        long long cost = tot_cost - totcst[i];
        long long left = totcnt[i];
        long long right = totcnt.back() - totcnt[i+1];
        cost += (left - right) * p.first - totp[i] + (totp.back() - totp[i+1]);

        // if (pr==2) {
        //     ps("cost", cost, "sz", sz(who), "pr", pr, "to", p.first);
        //     ps("left", left, "right", right);
        // }
        ret = min(ret, cost + split(p.second, pr-1));
        i++;
    }

    return ret;
}

void solve()
{
    re(n);
    rep(i,0,n) {int a; re(a); k[a]++;}

    for (int i = 2; i <= 5000; i++) if (!p[i]) {
        for (int j = i+i; j <= 5000; j += i) p[j]=i;
    }

    vector< pii > allfacts;
    for (int i = 5000; i >= 0; i--) if (k[i]) allfacts.push_back({i, k[i]});
    for (int i = 0; i <= 5000; i++) {
        for (int pr = 2; pr <= 5000; pr++) {
            cost[i][pr] = cost[i][pr-1];
            if (!p[pr]) cost[i][pr] += g(i,pr);
        }
    }

    ps(split(allfacts, 5000));
    // ps(cnt);
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void pr(long long x) { printf("%lld", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}