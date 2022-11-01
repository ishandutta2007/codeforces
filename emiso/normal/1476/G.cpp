#include <bits/stdc++.h>
#define MN 100100

using namespace std;
typedef long long ll;

int B = 2000; // N ^ (2/3)
int arr[MN], freq[MN], count_different;
int l = 0, r = -1, chronol = -1;

struct query {
    int l, r, t, id, k;

    query(int l, int r, int t, int id, int k) :
        l(l), r(r), t(t), id(id), k(k) {}

    bool operator <(const query &o) const {
        if(l / B != o.l / B) return l < o.l;
        if(r / B != o.r / B) return r < o.r;
        return t < o.t;
    }
};

int ff[MN], nval[MN];
vector<int> ffs;

void resolve_ffs() {
    vector<int> new_ffs;
    for(int x : ffs) {
        if(ff[x]) new_ffs.push_back(x);
        else nval[x] = 0;
    }
    sort(new_ffs.begin(), new_ffs.end());
    new_ffs.resize(unique(new_ffs.begin(), new_ffs.end()) - new_ffs.begin());
    ffs = new_ffs;
}

int solve_ffs(int k) {
    int l = 0, r = -1, sum = 0, best = INT_MAX;
    while(r + 1 < ffs.size()) {
        sum += ff[ffs[++r]];
        while(l <= r && sum - ff[ffs[l]] >= k)
            sum -= ff[ffs[l++]];
        if(l <= r && sum >= k) best = min(best, ffs[r] - ffs[l]);
    }
    return (best == INT_MAX) ? -1 : best;
}

void rem(int idx) {
    if(freq[arr[idx]] > 0) ff[freq[arr[idx]]]--;
    if(--freq[arr[idx]] == 0) count_different--;
    if(freq[arr[idx]] > 0) {
        ff[freq[arr[idx]]]++;
        if(!nval[freq[arr[idx]]]) {
            ffs.push_back(freq[arr[idx]]);
            nval[freq[arr[idx]]] = 1;
        }
    }
}

void add(int idx) {
    if(freq[arr[idx]] > 0) ff[freq[arr[idx]]]--;
    if(freq[arr[idx]]++ == 0) count_different++;
    if(freq[arr[idx]] > 0) {
        ff[freq[arr[idx]]]++;
        if(!nval[freq[arr[idx]]]) {
            ffs.push_back(freq[arr[idx]]);
            nval[freq[arr[idx]]] = 1;
        }
    }
}

struct update {
    int from, to, id;

    update(int to, int id) :
        id(id), to(to) {}

    void upd() {
        if(l <= id && id <= r) rem(id);
        from = arr[id];
        arr[id] = to;
        if(l <= id && id <= r) add(id);

        swap(from, to);
    }
};

vector<query> Q;
vector<update> U;
ll ans[MN];

void solve() {
    sort(Q.begin(), Q.end());
    for(int i = 0; i < Q.size(); i++) {
        int T = Q[i].t, L = Q[i].l, R = Q[i].r, K = Q[i].k;

        while(chronol < T) U[++chronol].upd();
        while(chronol > T) U[chronol--].upd();

        while(l > L) add(--l);
        while(l < L) rem(l++);

        while(r < R) add(++r);
        while(r > R) rem(r--);

        resolve_ffs();
        ans[Q[i].id] = solve_ffs(K);
    }
}

int n, q, t, a, b, c = -1, k;

int main() {
    scanf("%d %d", &n, &q);
    B = pow(n, 0.7) + 1;

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < q; i++) {
        scanf("%d %d %d", &t, &a, &b);
        if(t == 2) {
            a--;
            U.push_back(update(b, a));
            c++;
        } else {
            scanf("%d", &k);
            a--; b--;
            Q.push_back(query(a, b, c, Q.size(), k));
        }
    }

    solve();
    for(int i = 0; i < Q.size(); i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}