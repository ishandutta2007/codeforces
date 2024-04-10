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
vector <int> can;
void one(vector <int> &a, int u) {
    if (a[u]) {
        can.app(u);
        --a[u];
    }
}   
void allf(vector <int> &a, int u) {
    while (a[u]) {
        can.app(u);
        --a[u];
    }    
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    vector <int> a(n);
    int c = 0, sum = 0;
    vector <int> ar, l;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            ++c;
            l.app(i);
        }
        else {
            ar.app(i);
            sum += a[i];
        }
    }

    if (ar.empty()) {
        cout << "NO\n";
        exit(0);
    }   

    sort(all(ar));
    if (ar.size() > 1) {
        swap(ar[0], ar[ar.size() - 2]);
    }   

    vector <ii> ans;
    for (int i = 0; i + 1 < ar.size(); ++i) {
        ans.app(mp(ar[i], ar[i + 1]));
        --a[ar[i]];
        --a[ar[i + 1]];
    }

    int d = (int)ar.size() - 1;
    d += (bool)a[ar[0]] && l.size();
    d += (bool)a[ar.back()] && l.size() > 1;

    one(a, ar[0]);
    one(a, ar.back());
    for (int e : ar)
        allf(a, e);
    
    if (can.size() < l.size()) {
        cout << "NO\n";
        exit(0);
    }   
        
    int ptr = 0;
    for (int e : l) {
        ans.app(mp(e, can[ptr]));
        ++ptr;
    }   

    cout << "YES " << d << endl;
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e.f + 1 << ' ' << e.s + 1 << endl;
}