#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back

const int N = 5e5+7;
int n, k, p[N];
int nxt[N], in[N], pos[N], seg[N];
vector <int> s[N];
vector <int> g[N];

bool used[N];
vector <int> ord;
int pos_ord[N];
void dfs(int u) {
    used[u] = 1;
    for (int v : g[u])  
        if (!used[v])
            dfs(v);
    ord.app(u);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }   
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        nxt[x] = y;
        in[y]++;
    }   
    int ptr = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            int u = i;
            while (u) {
                sum++;
                seg[u] = ptr;
                pos[u] = s[ptr].size();
                s[ptr].app(u);
                u = nxt[u];
            }   
            ptr++;
        }   
    }   

    if (sum != n) {
        cout << 0 << endl;
        exit(0);
    }   

    for (int i = 1; i <= n; ++i) {
        if (p[i]) {
            int a = p[i];
            int b = i;
            if (seg[a] == seg[b]) {
                if (pos[a] > pos[b]) {
                    cout << 0 << endl;
                    exit(0);
                }   
            }   
            else {
                g[seg[a]].app(seg[b]);
            }   
        }
    }   

    for (int i = 0; i < ptr; ++i)
        if (!used[i])
            dfs(i);
    reverse(all(ord));

    for (int i = 0; i < ord.size(); ++i)
        pos_ord[ord[i]] = i;

    for (int i = 1; i <= n; ++i) {
        if (p[i]) {
            int a = p[i];
            int b = i;
            if (seg[a] != seg[b]) {
                if (pos_ord[seg[a]] > pos_ord[seg[b]]) {
                    cout << 0 << endl;
                    exit(0);
                }   
            }   
        }
    }   
    
    for (int c : ord) {
        for (auto e : s[c])
            cout << e << ' ';
    }   
    cout << endl;
}