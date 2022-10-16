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

void pr(int x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef pair<int, int> pii;

#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#include <cstring>

int t, n;
char s[210000];
int pos[210000];
int cnt[30];
int tcnt;
vector<pii> ans;
set<pii> groups_by_order[26];

int where(int x) {
    for (int y = x; y > 0; y -= y&-y) x -= pos[y];
    return x;
}

void upd(int x, int d) {
    for (int y = x; y <= n; y += y&-y) pos[y]+=d;
}

void go(int bigloc, int bigtam, int b, int otloc, int ottam, int d) {
    ans.push_back({where(bigloc+bigtam-1), where(otloc)});

    int tlen = (ans.back().second - ans.back().first + 1);
    upd(bigloc+bigtam-1, tlen);

    bigtam--;
    otloc++;
    ottam--;

    cnt[b]--; cnt[d]--;
    tcnt -= 2;

    if (ottam > 1) {
        groups_by_order[d].insert({otloc, ottam});
    }
    if (bigtam > 1) {
        groups_by_order[b].insert({bigloc, bigtam});
    }
}

void solve()
{
    for (re(t); t; t--) {
        scanf("%s", s);
        n = strlen(s);

        for (int i = 1; i <= n; i++) pos[i] = 0;
        for (int i = 0; i < 26; i++) cnt[i] = 0;
        tcnt = 0;

        // set< pair<int, int> > groups_by_size[26];
        for (int i = 0; i < 26; i++) groups_by_order[i].clear();

        int la = 0;
        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] != s[la]) {
                int tam = i - la;
                if (tam > 1) {
                    tcnt += tam-1;
                    cnt[s[la]-'a'] += tam-1;
                    groups_by_order[s[la]-'a'].insert({ la+1, tam });
                }
                la = i;
            }
        }

        ans.clear();

        int rem = n;
        while (rem) {
            if (tcnt == 0) {
                ans.push_back({1, rem});
            }

            else {
                int b = 0;
                for (int i = 0; i < 26; i++) if (cnt[i] > cnt[b]) b = i;

                if (cnt[b] == tcnt) {
                    pii g = *groups_by_order[b].begin();
                    groups_by_order[b].erase(g);

                    int loc = g.first;
                    int tam = g.second;
                    ans.push_back({1, where(loc)});

                    int tlen = (ans.back().second - ans.back().first + 1);
                    upd(1, tlen);

                    tam--;
                    loc++;
                    if (tam > 1) {
                        groups_by_order[b].insert({loc, tam});
                    }

                    tcnt--;
                    cnt[b]--;
                }

                else { 
                    pii big = *groups_by_order[b].begin();
                    int bigloc = big.first;
                    int bigtam = big.second;

                    int d = -1;
                    pii ot = {-1, -1};
                    for (int i = 0; i < 26; i++) if (i != b) {
                        auto it = groups_by_order[i].lower_bound({bigloc,bigtam});
                        if (it != groups_by_order[i].end()) {
                            if (d == -1 || it->first < ot.first) {
                                d = i;
                                ot = *it;
                            }
                        }
                    }

                    if (d != -1) {
                        int otloc = ot.first, ottam = ot.second;
                        groups_by_order[d].erase({ot.first, ot.second});

                        auto bigit = groups_by_order[b].lower_bound({otloc,ottam});
                        bigit--;

                        pii big = *bigit;
                        int bigloc = big.first;
                        int bigtam = big.second;
                        groups_by_order[b].erase(bigit);

                        go(bigloc,bigtam,b,otloc,ottam,d);
                    }

                    else {
                        for (int i = 0; i < 26; i++) if (i != b) {
                            auto it = groups_by_order[i].lower_bound({bigloc,bigtam});
                            if (it != groups_by_order[i].begin()) {
                                it--;
                                if (d == -1 || it->first > ot.first) {
                                    d = i;
                                    ot = *it;
                                }
                            }
                        }

                        {
                            int otloc = ot.first, ottam = ot.second;
                            groups_by_order[d].erase({ot.first, ot.second});

                            auto bigit = groups_by_order[b].lower_bound({otloc,ottam});

                            pii big = *bigit;
                            int bigloc = big.first;
                            int bigtam = big.second;
                            groups_by_order[b].erase(bigit);

                            go(otloc,ottam,d,bigloc,bigtam,b);
                        }
                    }
                }
            }

            rem -= (ans.back().second - ans.back().first + 1);
        }

        ps(sz(ans));
        rep(i,0,sz(ans)) {
            ps(ans[i].first,ans[i].second);
        }
    }
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}