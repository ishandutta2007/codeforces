#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e6 + 7;

int ptr;
int ans = 0;
int par[N], cnt[N], real_cnt[N], one[N];
bool prop[N], fix[N];
int root(int u) {
    while (par[u] != u) {
        u = par[u];
    }
    return u;
}   
int getcol(int u) {
    int ans = prop[u];
    while (par[u] != u) {
        u = par[u];
        ans ^= prop[u];
    }   
    return ans;
}   
void color(int u, int c, bool f) {
    //cout << "color " << u << ' ' << c << endl;
    int r = root(u);
    fix[r] |= f;
    if (getcol(u) == c)
        return;
    ans -= one[r];
    one[r] = real_cnt[r] - one[r];
    ans += one[r];
    prop[r] ^= 1;
}   
void edge(int u, int v) {
    //cout << "edge " << u << ' ' << v << endl;

    int ur = root(u);
    int vr = root(v);
    if (ur == vr)
        return;

    if (getcol(u) == getcol(v)) {
        int addu = real_cnt[ur] - 2 * one[ur];
        int addv = real_cnt[vr] - 2 * one[vr];
        
        if (!fix[ur] && (addu < addv || fix[vr])) {
            color(u, getcol(u) ^ 1, 0);
        }   
        else {
            color(v, getcol(v) ^ 1, 0);
        }   
    }

    if (cnt[ur] > cnt[vr])
        swap(ur, vr);
    prop[ur] ^= prop[vr];
    par[ur] = vr;
    cnt[vr] += cnt[ur];
    real_cnt[vr] += real_cnt[ur];
    one[vr] += one[ur];
    fix[vr] |= fix[ur];
}

int n, k;
string s;
vector <int> in[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < N; ++i) {
        par[i] = i;
        cnt[i] = 1;
    }   
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < k; ++i) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            int e;
            cin >> e;
            --e;
            in[e].app(i);
        }   
    }   
    for (int i = 0; i < k; ++i) {
        real_cnt[i] = 1;
    }
    ptr = k;
    for (int i = 0; i < n; ++i) {
        if (in[i].empty()) {

        }
        else if (in[i].size() == 1) {
            if (s[i] == '1') 
                color(in[i][0], 0, 1);
            else
                color(in[i][0], 1, 1);
        }
        else {
            if (s[i] == '1') {
                edge(ptr, in[i][0]);
                edge(ptr, in[i][1]);
                ++ptr;
            }   
            else {
                edge(in[i][0], in[i][1]);
            }   
        }   
        cout << ans << '\n';
    }   
}