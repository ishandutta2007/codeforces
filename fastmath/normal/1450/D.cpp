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
#define debug(x) std::cout << #x << ": " << x << '\n';
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
        vector <int> a(n), l(n), r(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        vector <int> maxlen(n + 1);
        
        {
        vector <int> s;
        for (int i = 0; i < n; ++i) {
            while (s.size() && a[s.back()] >= a[i]) {
                s.pop_back();
            }   
            if (s.size()) {
                l[i] = s.back();
            }
            else {
                l[i] = -1;
            }   
            s.app(i);
        }   
        }

        {
        vector <int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (s.size() && a[s.back()] >= a[i]) {
                s.pop_back();
            }   
            if (s.size()) {
                r[i] = s.back();
            }
            else {
                r[i] = n;
            }   
            s.app(i);
        }   
        }

        for (int i = 0; i < n; ++i) {
            maxlen[a[i]] = max(maxlen[a[i]], r[i] - l[i] - 1);
        }   

        vector <int> bad(n + 7);
        for (int x = 1; x <= n; ++x) {
            int l = maxlen[x] + 1;
            int r = n + 1 - x;

            //cout << x << ' ' << l << ' ' << r << endl;

            if (l <= r) {
                bad[l]++;
                bad[r + 1]--;                
            }   
        }   

        for (int i = 1; i <= n; ++i) {
            bad[i] += bad[i - 1];
            if (bad[i])
                cout << '0';
            else
                cout << '1';
        }
        cout << endl;
    }   
}