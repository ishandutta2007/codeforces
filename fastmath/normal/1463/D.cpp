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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <bool> used(2 * n + 1);
        vector <int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            used[b[i]] = 1;
        }             
        sort(all(b));
        vector <int> a;
        for (int i = 1; i <= 2 * n; ++i)
            if (!used[i])
                a.app(i);

        int L, R;

        {
        int l = 0;
        int r = n + 1;

        auto check = [&] (int k) {
            int ptr_a = n - 1;
            int ptr_b = k - 1;

            int bal = 0;
            while (ptr_a >= 0 && ptr_b >= 0) {
                if (a[ptr_a] > b[ptr_b]) {
                    bal++;
                    ptr_a--;
                }   
                else {
                    bal--;
                    ptr_b--;
                }   
                if (bal < 0)
                    return 0;
            }   

            while (ptr_b >= 0) {
                bal--;
                ptr_b--;
                if (bal < 0)
                    return 0;
            }   

            return 1;
        };

        while (l < r - 1) {
            int m = (l + r) >> 1;            
            if (check(m))
                l = m;
            else
                r = m;
        }
        R = l;
        }   

        {

        auto check = [&] (int m) {
            int ptr_a = 0;
            int ptr_b = n - m;
            int bal = 0;
            while (ptr_a < n && ptr_b < n) {
                if (a[ptr_a] < b[ptr_b]) {
                    bal++;
                    ptr_a++;
                }   
                else {
                    bal--;
                    ptr_b++;
                }   
                if (bal < 0)
                    return 0;
            }   
            while (ptr_b < n) {
                bal--;
                ptr_b++;
                if (bal < 0)
                    return 0;
            }   
            return 1;
        };  

        int l = 0;
        int r = n + 1;
        while (l < r - 1) {
            int m = (l + r) >> 1;
            if (check(m))
                l = m;
            else
                r = m;
        }   
        L = n - l;
        }

        //debug(L);
        //debug(R);

        if (L <= R)
            cout << R - L + 1 << endl;
        else
            cout << 0 << endl;
    }   
}