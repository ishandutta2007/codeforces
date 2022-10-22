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

const int N = 1e6 + 7;
int tree[N << 2];
void add(int v, int tl, int tr, int i) {
    ++tree[v];
    if (tl == tr)
        return;
    int tm = (tl + tr) >> 1;
    if (i <= tm)
        add(v * 2 + 1, tl, tm, i);
    else
        add(v * 2 + 2, tm + 1, tr, i);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}   
void del(int v, int tl, int tr, int k) {
    --tree[v];
    if (tl == tr) 
        return;
    int tm = (tl + tr) >> 1;
    if (k <= tree[v * 2 + 1])
        del(v * 2 + 1, tl, tm, k);
    else
        del(v * 2 + 2, tm + 1, tr, k - tree[v * 2 + 1]);
}   
void print(int v, int tl, int tr) {
    if (tl == tr) {
        cout << tl << endl;
        exit(0);
    }   
    int tm = (tl + tr) >> 1;
    if (tree[v * 2 + 1])
        print(v * 2 + 1, tl, tm);
    else
        print(v * 2 + 2, tm + 1, tr);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        add(0, 1, n, x);
    }   
    while (q--) {
        int x;
        cin >> x;
        if (x > 0) {
            add(0, 1, n, x);
        }   
        else {
            del(0, 1, n, -x);
        }   
    }       
    if (tree[0])
        print(0, 1, n);
    else
        cout << 0 << endl;
}