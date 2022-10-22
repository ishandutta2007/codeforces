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

const int N = 1 << 21;
int a[N];

int get(int v) {
    if (a[v * 2] == 0 && a[v * 2 + 1] == 0)
        return v;
    else if (a[v * 2] > a[v * 2 + 1])   
        return get(v * 2);
    else
        return get(v * 2 + 1);
}   

void del(int v) {
    if (a[v * 2] == 0 && a[v * 2 + 1] == 0) {
        a[v] = 0;
        return;
    }
    else if (a[v * 2] > a[v * 2 + 1]) {
        a[v] = a[v * 2];
        del(v * 2);
    }
    else {
        a[v] = a[v * 2 + 1];
        del(v * 2 + 1);
    }
}   

void solve() {
    int h, g;
    cin >> h >> g;
    for (int i = 0; i < (1 << (h + 1)); ++i)
        a[i] = 0;
    for (int i = 1; i < (1 << h); ++i)
        cin >> a[i];
    vector <ii> ar;
    for (int i = 1; i < (1 << h); ++i) {
        ar.app(mp(a[i], i));
    }   
    sort(all(ar));
    reverse(all(ar));
    vector <int> ans;
    for (auto e : ar) {
        int v = e.s;
        while (a[v]) {
            int to = get(v);
            if (to < (1 << g))
                break;
            del(v);
            ans.app(v);
        }   
    }   
    int sum = 0;
    for (int i = 1; i < (1 << g); ++i)
        sum += a[i];
    cout << sum << endl;
    for (int e : ans)
        cout << e << ' ';
    cout << endl;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--)
        solve();
}