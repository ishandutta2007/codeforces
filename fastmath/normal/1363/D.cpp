#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

int query(vector <int> a) {
    cout << "? " << a.size() << ' ';
    for (auto e : a)
        cout << e << ' ';
    cout << endl;
    fflush(stdout);
    
    int ans;
    cin >> ans;
    return ans;
}   

void print(vector <int> a) {
    cout << "! ";
    for (auto e : a)
        cout << e << ' ';
    cout << endl;
    fflush(stdout);
}   

struct Set {
    int i;
    vector <int> a;
};

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <Set> a;
        for (int i = 0; i < k; ++i) {   
            int sz; cin >> sz;
            a.app({i, {}});
            for (int j = 0; j < sz; ++j) {
                int x; cin >> x;
                a.back().a.app(x);
            }   
        }

        vector <int> all;
        for (int i = 1; i <= n; ++i)
            all.app(i);
        int mx = query(all);
        vector <Set> can = a;
        while (can.size() > 1) {
            int m = can.size()/2;
            vector <Set> l, r;
            for (int i = 0; i < m; ++i)
                l.app(can[i]);
            for (int i = m; i < can.size(); ++i)
                r.app(can[i]);

            vector <int> alll;
            for (auto e : l)
                for (int i : e.a)
                    alll.app(i);
             if (query(alll) == mx) {
                can = l;
             }  
             else {
                can = r;
             }  
        }   

        vector <int> ans(k, mx);

        vector <bool> used(n + 1);
        for (int i : can[0].a)
            used[i] = 1;
        vector <int> oth;
        for (int i = 1; i <= n; ++i)
            if (!used[i])
                oth.app(i);

        ans[can[0].i] = query(oth);
        print(ans);

        string t;
        cin >> t;
        if (t != "Correct") {
            exit(0);
        }   
    }   
}