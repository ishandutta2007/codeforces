#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,tune=native")

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct node {
    node* ch[2] = {};
    int c = 0;  
};

node root;

void ins(int k) {
    node* cur = &root;
    for (int i = 30; i >= 0; i--) {
        int m = (k>>i)&1;
        if (cur->ch[m] == NULL)
            cur->ch[m] = new node;
        cur->c++;
        cur = cur->ch[m];
    }
    cur->c++;
}

void rem(int k) {
    node* cur = &root;
    for (int i = 30; i >= 0; i--) {
        int m = (k>>i)&1;
        cur->c--;
        cur = cur->ch[m];
    }
    cur->c--;
}

int get(int k) {
    node* cur = &root;
    int r = 0;
    for (int i = 30; i >= 0; i--) {
        int m = (k>>i)&1;
        if (cur->ch[m] == NULL || cur->ch[m]->c == 0) {
            r ^= 1<<i;
            cur = cur->ch[m^1];
        } else {
            cur = cur->ch[m];
        }
    }
    return r;
}

const int maxn = 200005;
int a[maxn];
ll out = 0;

void solve(int l, int r, int k) {
    if (l >= r || k < 0) return;
    int m = l;
    while (m <= r && !(a[m]&(1<<k))) m++;
    if (m-l > 0 && r-m+1 > 0) {
        for (int i = l; i < m; i++)
            ins(a[i]);
        int x = inf;
        for (int i = m; i <= r; i++)
            x = min(x, get(a[i]));
        for (int i = l; i < m; i++)
            rem(a[i]);
        out += (ll)x;
    }
    solve(l, m-1, k-1);
    solve(m, r, k-1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    solve(0, n-1, 30);
    cout << out << "\n";
}