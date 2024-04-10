#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
// #include "../../debug.cpp"
#endif

vector<vector<int>> s;

int query(int a, int b) {
    vector<int> q;
    for (int i = a; i <= b; i++)
        for (auto& x : s[i])
            q.pb(x);
    cout << "? " << q.size();
    for (auto& x : q) cout << " " << x;
    cout << endl;
    int r; cin >> r;
    if (r == -1) exit(0);
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        s.assign(k, {});
        for (int i = 0; i < k; i++) {
            int c; cin >> c; s[i].resize(c);
            for (auto& x : s[i])
                cin >> x;
        }
        cout << "? " << n;
        for (int i = 0; i < n; i++)
            cout << " " << i+1;
        cout << endl;
        int x; cin >> x;
        if (x == -1) exit(0);
        int a = 0, b = k-1;
        while (a < b) {
            int m = (a+b)/2;
            if (query(a, m) == x)
                b = m;
            else
                a = m+1;
        } 
        cout << "? " << n-s[a].size();
        for (int i = 0; i < n; i++)
            if (find(all(s[a]), i+1) == s[a].end())
                cout << " " << i+1;
        cout << endl;
        int y; cin >> y;
        if (y == -1) exit(0);
        cout << "!";
        for (int i = 0; i < k; i++) {
            if (i == a)
                cout << " " << y;
            else
                cout << " " << x;
        }
        cout << endl;
        string r; cin >> r;
        if (r == "Incorrect") exit(0);
    }
}