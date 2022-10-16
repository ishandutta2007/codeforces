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

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef pair<int, int> pii;

#define all(v) (v).begin(), (v).end()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n,q;
int a[310000];
vector<int> pos[310000];

struct query {
    int l,r,k,i;
};

int cands[310000];
int bst_right[310000][4];
int freq[310000];

int cnt(int val, int l, int r) {
    int rr = lower_bound(all(pos[val]), r+1) - pos[val].begin();
    int ll = lower_bound(all(pos[val]), l) - pos[val].begin();
    return rr - ll;
}

void dnc(int l, int r, vector<query> & qs) {
    // dbg(l,r);
    if (qs.empty() || l > r) return;

    vector<query> left, right;
    vector<pii> now;

    int m = (l+r+1)/2;
    
    for (int i = m; i <= r; i++) freq[a[i]] = 0;

    // dbg("hi");

    set< pair<int, int> > freqset;
    for (int i = m; i <= r; i++) {
        freqset.erase({-freq[a[i]], a[i]});
        freq[a[i]]++;
        freqset.insert({-freq[a[i]], a[i]});

        auto it = freqset.begin();
        for (int j = 0; j < 4; j++) {
            // dbg(i,j);
            if (it == freqset.end()) bst_right[i][j] = -1;
            else {
                bst_right[i][j] = it->second;
                it++;
            }
        }
    }

    // dbg("hi");
    for (int i = l; i < m; i++) freq[a[i]] = 0;

    freqset.clear();
    for (int i = m-1; i >= l; i--) {
        freqset.erase({-freq[a[i]], a[i]});
        freq[a[i]]++;
        freqset.insert({-freq[a[i]], a[i]});

        auto it = freqset.begin();
        for (int j = 0; j < 4; j++) {
            if (it == freqset.end()) bst_right[i][j] = -1;
            else {
                bst_right[i][j] = it->second;
                it++;
            }
        }
    }

    // dbg("hi");

    for (auto qry : qs) {
        if (qry.l <= m && qry.r >= m) {
            int best = -1;
            for (int j = 0; j < qry.k-1; j++) {
                int ri_cand = bst_right[qry.r][j];
                if (ri_cand != -1) {
                    // dbg("testing", ri_cand, "for", qry.i);
                    int cc = cnt(ri_cand, qry.l, qry.r);
                    if (cc*qry.k > (qry.r - qry.l + 1)) {
                        if (best == -1 || ri_cand < best) best = ri_cand;
                    } 
                }

                if (qry.l < m) {
                    int ri_cand = bst_right[qry.l][j];
                    if (ri_cand != -1) {
                        int cc = cnt(ri_cand, qry.l, qry.r);
                        if (cc*qry.k > (qry.r - qry.l + 1)) {
                            if (best == -1 || ri_cand < best) best = ri_cand;
                        } 
                    }
                }
            }

            cands[qry.i] = best;
            continue;
        }

        if (qry.l < m) left.push_back(qry);
        if (qry.r > m) right.push_back(qry);
    }

    qs.clear();
    qs.shrink_to_fit();

    if (l != r) {
        dnc(l, m-1, left);
        dnc(m+1, r, right);
    }
}

void solve()
{
    re(n,q);

    rep(i,0,n) {
        re(a[i]);
        pos[a[i]].push_back(i);
    }

    vector<query> qs;
    rep(i,0,q) {
        int l,r,k; re(l,r,k); l--; r--;
        qs.push_back({l,r,k,i});
    }

    dnc(0, n-1, qs);
    rep(i,0,q) ps(cands[i]);
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

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}