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

template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(int x);

void pr(const char *x);

template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

set< int, greater<int> > fr;
int n, q;

int a[210000];
pair< pair<int, int>, int> queries[210000];
vi ans[210000];
int cnt[210000];

void solve()
{
    re(n,q);
    rep(i,0,n) re(a[i]);

    rep(i,0,q) {
        re(queries[i].first.second, queries[i].first.first);
        queries[i].second = i;
    }

    sort(queries, queries+q);

    int nxt = 0;
    vi seq;
    vi seq3;

    vi maxs, mins;

    rep(i,0,q) {
        int l = queries[i].first.second, r = queries[i].first.first;
        int q_idx = queries[i].second;

        while (nxt < r) {
            cnt[nxt] = 2;
            while (!maxs.empty() && a[maxs.back()] < a[nxt]) {
                int freed = maxs.back();
                maxs.pop_back();
                if (--cnt[freed] == 0) {
                    fr.insert(freed);
                }
            }
            while (!mins.empty() && a[mins.back()] > a[nxt]) {
                int freed = mins.back();
                mins.pop_back();
                if (--cnt[freed] == 0) {
                    fr.insert(freed);
                }
            }

            maxs.push_back(nxt);
            mins.push_back(nxt);

            if (nxt > 0 && a[nxt] != a[nxt-1]) {
                int min_idx = lower_bound(all(mins), nxt, [](int c, int d) {return a[c]<a[d];}) - mins.begin() - 1;             
                int max_idx = lower_bound(all(maxs), nxt, [](int c, int d) {return a[c]>a[d];}) - maxs.begin() - 1;

                if (max_idx != -1) {
                    max_idx = maxs[max_idx];
                    auto it = fr.lower_bound(max_idx);
                    if (it != fr.end()) {
                        if (seq3.empty() || *it > seq3[0]) {
                            seq3 = {*it, max_idx, nxt};
                        }
                    }
                }

                if (min_idx != -1) {
                    min_idx = mins[min_idx];
                    auto it = fr.lower_bound(min_idx);
                    if (it != fr.end()) {
                        if (seq3.empty() || *it > seq3[0]) {
                            // dbg(*it,min_idx,i);
                            seq3 = {*it, min_idx, nxt};
                        }
                    }
                }

                // dbg(r, nxt, sz(maxs), sz(mins));
                if (sz(maxs) >= 2 && sz(mins) >= 2) {
                    int mai = maxs[sz(maxs)-2], mii = mins[sz(mins)-2];
                    if (mai < mii) swap(mii, mai);

                    // dbg(mii,mai,i);
                    if (seq3.empty() || mii > seq3[0]) {
                        seq3 = {mii,mai,nxt};
                    }
                }

                if (max_idx != -1 && min_idx != -1) {
                    auto it = fr.lower_bound(min(max_idx, min_idx));
                    if (it != fr.end()) {
                        int mii = *lower_bound(all(mins), *it);
                        int mai = *lower_bound(all(maxs), *it);
                        // dbg("found", *it, min(min_idx, max_idx), max(min_idx, max_idx), nxt);
                        // dbg(maxs);
                        // dbg(mins);
                        if (seq.empty() || *it > seq[0]) {
                            seq = {*it, min(mii,mai), max(mii,mai), nxt};
                        }
                    }
                }
            }

            nxt++;
        }

        l--;
        if (!seq.empty() && l <= seq[0]) {
            ans[q_idx] = seq;
        }
        else if (!seq3.empty() && l <= seq3[0]) {
            ans[q_idx] = seq3;
        }
    }

    rep(i,0,q) {
        ps(sz(ans[i]));
        if (!ans[i].empty()) {
            rep(j,0,sz(ans[i])) pr(ans[i][j]+1," ");
            ps();
        }
    }
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}