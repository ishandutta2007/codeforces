#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2e5 + 7;
bool inv[N], a[N];
int n, k;
char getl(int i) {
    if (i == 0) return a[n - 1];
    else return a[i - 1];
}   
char getr(int i) {
    if (i == n - 1) return a[0];
    else return a[i + 1];
}   
char get(int x) {
    if (x & 1) return 'W';
    else return 'B';
}   
int get(int l, int r) {
    if (l < r) return r - l - 1;
    else return n - l - 1 + r;
}   
int l[N], r[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    string s; cin >> s;
    for (int i = 0; i < n; ++i) a[i] = s[i] == 'W';
    for (int i = 0; i < n; ++i) inv[i] = getl(i) == a[i] || getr(i) == a[i];
    bool c = 0;
    for (int i = 0; i < n; ++i) {
        c |= inv[i];
    }   
    if (!c) {
        for (int i = 0; i < n; ++i) cout << get(a[i] + k);
        cout << '\n';
        exit(0);
    }
    for (int i = 0; i < n; ++i) {
        if (inv[i]) {
            l[i] = r[i] = i;
        }   
        else {
            l[i] = r[i] = -1;
        }   
    }   
    int cur = -1;
    for (int i = 0; i < n; ++i) {
        if (inv[i]) cur = i;
    }   
    for (int i = 0; i < n; ++i) {
        if (inv[i]) cur = i;
        else l[i] = cur;
    }   
    cur = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (inv[i]) cur = i;
    }   
    for (int i = n - 1; i >= 0; --i) {
        if (inv[i]) cur = i;
        else r[i] = cur;
    }   
    for (int i = 0; i < n; ++i) {
        if (inv[i]) cout << get(a[i]);
        else {
            int ml = get(l[i], i), mr = get(i, r[i]);
            int len = ml + mr + 1;
            if (k >= (len + 1) / 2) {
                if (ml < mr) cout << get(a[l[i]]);
                else cout << get(a[r[i]]);
            }   
            else if (ml + 1 <= k) cout << get(a[l[i]]);
            else if (mr + 1 <= k) cout << get(a[r[i]]);
            else cout << get(a[i] + k);
        }   
    }   
    cout << '\n';
}