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

const int N = 2e5+7;

set <int> a[N], b[N];
int maxa[N << 2], minb[N << 2];
int badv = 0;

bool bad(int v, int l, int r) {
    if (l == r) {
        return a[l].size() && b[l].size() && *a[l].rbegin() >= *b[l].begin();
    }
    else {
        return maxa[v * 2 + 2] >= minb[v * 2 + 1];
    }   
}   

void relax(int v) {
    maxa[v] = max(maxa[v * 2 + 1], maxa[v * 2 + 2]);
    minb[v] = min(minb[v * 2 + 1], minb[v * 2 + 2]);
}   

void upd_a(int v, int l, int r, int x, int y) {
    if (l == r) {

        badv -= bad(v, l, r);

        if (a[x].find(y) == a[x].end())
            a[x].insert(y);
        else
            a[x].erase(y);

        if (a[x].empty())
            maxa[v] = -N;
        else
            maxa[v] = *a[x].rbegin();

        badv += bad(v, l, r);

        return;    
    }   

    badv -= bad(v, l, r);
    int m = (l + r) >> 1;
    if (x <= m)
        upd_a(v * 2 + 1, l, m, x, y);
    else
        upd_a(v * 2 + 2, m + 1, r, x, y);
    
    relax(v);
    badv += bad(v, l, r);
}   

void upd_b(int v, int l, int r, int x, int y) {
    if (l == r) {

        badv -= bad(v, l, r);

        if (b[x].find(y) == b[x].end())
            b[x].insert(y);
        else 
            b[x].erase(y);

        if (b[x].empty())
            minb[v] = N;
        else
            minb[v] = *b[x].begin();

        badv += bad(v, l, r);

        return;    
    }   
    badv -= bad(v, l, r);
    int m = (l + r) >> 1;
    if (x <= m)
        upd_b(v * 2 + 1, l, m, x, y);
    else
        upd_b(v * 2 + 2, m + 1, r, x, y);

    relax(v);
    badv += bad(v, l, r);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int i = 0; i < (N << 2); ++i) {
        maxa[i] = -N;
        minb[i] = N;
    }   

    int n, m, q;
    cin >> n >> m >> q;
    while (q--) {

        int x, y;
        cin >> x >> y;

        --x; --y;

        //cout << x/2 << ' ' << y/2 << endl;

        if (x & 1) {
            upd_a(0, 0, N, x/2, y/2);
        }
        else {
            upd_b(0, 0, N, x/2, y/2);
        }   

        if (badv == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;                    
    }   

}