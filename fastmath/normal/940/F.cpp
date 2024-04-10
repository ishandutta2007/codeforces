#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
const int K = 2000;

int n, q;
int a[MAXN];
int tmp[MAXN];

struct Quer {
    int t, a, b, num, w;
};  

Quer d[MAXN];

void read() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) {
        cin >> d[i].t >> d[i].a >> d[i].b;
        d[i].num = i;
        if (d[i].t == 1) {
            --d[i].a; --d[i].b;
        }
        else {
            --d[i].a;
        }   
    }
    for (int i = 0; i < n; ++i) tmp[i] = a[i];
    for (int i = 0; i < q; ++i) {
        if (d[i].t == 2) {
            d[i].w = tmp[d[i].a];
            tmp[d[i].a] = d[i].b;
        }   
    }   
}

bool comp(Quer a, Quer b) {
    return (a.t / K < b.t / K) || (a.t / K == b.t / K && a.a / K < b.a / K) || (a.t / K == b.t / K && a.a / K == b.a / K && a.b < b.b);
}

void compr() {
    vector <int> v;
    for (int i = 0; i < n; ++i) v.push_back(a[i]);
    for (int i = 0; i < q; ++i) if (d[i].t == 2) v.push_back(d[i].b);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < n; ++i) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    for (int i = 0; i < q; ++i) {
        if (d[i].t == 2) {
            d[i].w = lower_bound(v.begin(), v.end(), d[i].w) - v.begin() + 1;
            d[i].b = lower_bound(v.begin(), v.end(), d[i].b) - v.begin() + 1;
        }
    }
}

int ans[MAXN];
int cnt[MAXN];
int cntcnt[MAXN];

void add_(int x) {
    //cout << "add " << x << '\n';
    --cntcnt[cnt[x]];
    ++cnt[x];
    ++cntcnt[cnt[x]];
}

void del_(int x) {
    //cout << "del " << x << '\n';
    --cntcnt[cnt[x]];
    --cnt[x];
    ++cntcnt[cnt[x]];
}   

void add(int i) {
    add_(a[i]);
}

void del(int i) {
    del_(a[i]);
}   

vector <Quer> gt, pd;

void tadd(int t, int l, int r) {
    a[pd[t].a] = pd[t].b;
    if (l <= pd[t].a && pd[t].a <= r) {
        del_(pd[t].w);
        add_(pd[t].b);
    }
}

void tdel(int t, int l, int r) {
    a[pd[t].a] = pd[t].w;
    if (l <= pd[t].a && pd[t].a <= r) {
        add_(pd[t].w);
        del_(pd[t].b);
    }
}

int get() {
    for (int i = 1; ; ++i) {
        if (!cntcnt[i]) return i;
    }
    exit(1);
}   

int pref[MAXN];
void solve() {
    compr();

    for (int i = 0; i < q; ++i) {
        if (d[i].t == 1) gt.push_back(d[i]);
        else pd.push_back(d[i]);
    }
    
    pref[0] = (d[0].t == 2);
    for (int i = 1; i < q; ++i) {
        pref[i] = pref[i - 1] + (d[i].t == 2);
    }

    for (auto &e : gt) e.t = pref[e.num];
    sort(gt.begin(), gt.end(), comp);

    int l = 0;
    int r = -1;
    int t = 0;
    for (auto e : gt) {
        while (r < e.b) add(++r);
        while (l > e.a) add(--l);
        while (r > e.b) del(r--);
        while (l < e.a) del(l++);

        while (t < e.t) tadd(t++, l, r);
        while (t > e.t) tdel(--t, l, r);
        ans[e.num] = get();
    }
}

void print() {
    for (int i = 0; i < q; ++i) if (d[i].t == 1) cout << ans[i] << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);                

    read();
    solve();
    print();                             

    return 0;
}