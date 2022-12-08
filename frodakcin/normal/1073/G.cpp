#include <iostream>
#include <cstdio>

#include <vector>
#include <map>
#include <utility>

#include <cassert>
#include <algorithm>

using namespace std;

const int LC = 96;
#define ti(x) static_cast<int>(x)
const int MAXN = 2e5 + 1000;
typedef vector<int> vi;
#define pb push_back

char s[MAXN];

int N, Q;
int sa[MAXN], isa[MAXN], lcp[MAXN];
int rnk[MAXN][2], nrnk[MAXN];

vi cntarr[MAXN];
void cntsort(const int& mx, const int& v) {
    for(int i = 0;i < N;i++) cntarr[rnk[sa[i]][v]].pb(sa[i]);
    int ctr = 0;
    for(int i = 0;i <= mx;i++) {
        for(int j : cntarr[i]) sa[ctr++] = j;
        cntarr[i].clear();
    }
}
void radixsort(const int& mx) {
    for(int i = 1;i >= 0;i--) cntsort(mx, i);
}
bool sm(const int& a, const int& b) {
    for(int i = 0;i < 2;i++) if(rnk[a][i] != rnk[b][i]) return false;
    return true;
}
void gsa() {
    for(int i = 0;i < N;i++) sa[i] = i, rnk[i][0] = ti(s[i]) - LC, rnk[i][1] = 0;
    radixsort(28);
    for(int l = 1, ctr;l <= N;l <<= 1) {
        nrnk[sa[0]] = ctr = 1;
        for(int i = 1;i < N;i++) nrnk[sa[i]] = sm(sa[i - 1], sa[i]) ? ctr : ++ctr;
        for(int i = 0;i < N;i++) {
            rnk[i][0] = nrnk[i];
            rnk[i][1] = i + l < N ? nrnk[i + l] : 0;
        }
        radixsort(ctr);
    }
    for(int i = 0;i < N;i++) isa[sa[i]] = i;
}
void glcp() {
    for(int i = 0, p = 0;i < N;i++) {
        if(isa[i] == N - 1) {
            p = 0;
            lcp[N - 1] = -1;
            continue;
        }
        while(i + p < N and sa[isa[i] + 1] + p < N and s[i + p] == s[sa[isa[i] + 1] + p]) p++;
        lcp[isa[i]] = p;
        if(p) p--;
    }
}

int log2(int n) {
    int r = 1;
    while(n >>= 1) r++;
    return r;
}
int spt[MAXN][25];
void gspt() {
    for(int i = 0;i <= N;i++) for(int j = log2(N);j >= 0;j--) spt[i][j] = -1;
    for(int i = N - 1;i >= 0;i--) for(int j = 0;i + (1<<j) < N;j++) if(j) spt[i][j] = min(spt[i][j-1], spt[i+(1<<(j-1))][j-1]); else spt[i][j] = lcp[i];
}

typedef map<int, int> mapi;
#define IT iterator
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
#define mp make_pair
typedef long long ll;
#define tll(x) static_cast<ll>(x)

int K, L, k[MAXN], l[MAXN];
pib c[MAXN * 2];

void add(mapi& dat, const int& k, const int& v = 0) {
    if(dat.find(k) == dat.end()) dat.insert(mp(k, v));
    else dat[k] += v;
}
void lower(mapi& dat, ll& rc, const int& v) {
    if(v == 0) {rc = 0;dat.clear();return;}
    if(dat.empty()) return;
    mapi::IT p = dat.end(), c = p--;
    int ch = 0;
    while((c = p)->first > v) {
        ch += c->second;
        rc -= tll(c->first - v)*c->second;
        if(c == dat.begin()) {dat.erase(c);break;}
        p--;
        dat.erase(c);
    }
    add(dat, v, ch);
}
int jump(int i, int f) {  //LOG(D) time
    if(i == f) return N - sa[i];
    if(i > f) swap(i, f);
    int d = f - i, r = N - sa[i];
    for(int j = log2(d);j >= 0;j--) {
        if(i + (1<<j) > f) continue;
        if(spt[i][j] < r) r = spt[i][j];
        i += (1<<j);
    }
    assert(i == f and r >= 0);
    return r;
}
mapi dat;
void solve() {
    scanf("%d%d", &K, &L);
    for(int i = 0;i < K;i++) scanf("%d", k + i), c[i] = mp(--k[i], false);
    for(int i = 0;i < L;i++) scanf("%d", l + i), c[K + i] = mp(--l[i], true);
    
    ll ans = 0, rc = 0;
    
    sort(c, c + (K+L), [](const pib& a, const pib& b){return isa[a.first] < isa[b.first] or (not (isa[b.first] < isa[a.first]) and a.second < b.second);});
    
    dat.clear();
    for(int i = 0, p = 0;i < K+L;i++) {
        lower(dat, rc, jump(p, isa[c[i].first]));
        if(c[i].second) {
            int l = N - c[i].first;
            add(dat, l, 1);
            rc += l;
        }
        else
        {
            ans += rc;
        }
        p = isa[c[i].first];
    }
    dat.clear(), rc = 0;
    for(int i = K+L-1, p = N-1;i >= 0;i--) {
        lower(dat, rc, jump(p, isa[c[i].first]));
        if(c[i].second) {
            int l = N - c[i].first;
            add(dat, l, 1);
            rc += l;
        }
        else
        {
            ans += rc;
        }
        p = isa[c[i].first];
    }
    
    printf("%lld\n", ans);
}

int main() {
    scanf("%d%d", &N, &Q);
    scanf(" %s", s);
    
    gsa();
    glcp();
    gspt();
    
    while(Q--) solve();
    
    return 0;
}