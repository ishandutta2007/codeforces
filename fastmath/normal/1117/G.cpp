#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 7;
int n, q;
int a[N];
int l[N], r[N];
void read() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) cin >> l[i];
    for (int i = 0; i < q; ++i) cin >> r[i];
    for (int i = 0; i < q; ++i) {
        --l[i]; --r[i];
    }   
}
int ans[N];
int link[N];
vector <int> add[N], del[N];
int f[N], fcnt[N];
void addf(int i) {
    int t = i;
    for (; i < N; i |= (i + 1)) {
        f[i] += t;
    }   
}   
void addfcnt(int i) {
    for (; i < N; i |= (i + 1)) {
        fcnt[i]++;
    }   
}   
void add_(int i) {
    //cout << "add " << i << '\n';
    addf(i);
    addfcnt(i);
}   
int getsum(int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        ans += f[i];
    }   
    return ans;
}   
int getcnt(int i) {
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
        ans += fcnt[i];
    }   
    return ans;
}   
int getmax(int x) {
    return getcnt(x) * x + getsum(N - 1) - getsum(x);
}   
int pref[N];
void kek() {
    for (int i = 0; i < N; ++i) {
        f[i] = fcnt[i] = 0;
    }   
    for (int i = 0; i < q; ++i) {
        ans[i] += pref[r[i] + 1] - pref[l[i]];
    }
    for (int i = 0; i < N; ++i) f[i] = fcnt[i] = 0;
    for (int i = 0; i < n; ++i) {
        add[i].clear(); del[i].clear();
    }   
    for (int i = 0; i < n; ++i) link[i] = -1;
    vector <int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (st.size() && a[i] > a[st.back()]) {
            link[st.back()] = i;
            st.pop_back();
        }   
        st.push_back(i);
    }   
    for (int i = 0; i < q; ++i) {
        add[r[i]].push_back(i);
        if (l[i]) del[l[i] - 1].push_back(i);
    }

    /*
    if l <= link[i]: i - link[i] - 1
    else i - l
    i - max(link[i] + 1, l)
    */

    for (int i = 0; i < n; ++i) {
        add_(link[i] + 1);    
        for (int e : add[i]) {
            ans[e] -= getmax(l[e]);
        }
        for (int e : del[i]) {
            ans[e] += getmax(l[e]);    
        }
    }   
}   
void solve() {
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + i;
    }   
    for (int i = 0; i < q; ++i) {
        ans[i] = r[i] - l[i] + 1;
    }
    kek();
    reverse(a, a + n);
    for (int i = 0; i < q; ++i) {
        l[i] = n - 1 - l[i];
        r[i] = n - 1 - r[i];
        swap(l[i], r[i]);
    }
    kek();            
}
void print() {
    for (int i = 0; i < q; ++i) cout << ans[i] << ' ';
    cout << '\n';
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    read();
    solve();
    print();
}