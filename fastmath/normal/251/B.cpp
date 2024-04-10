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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, k;
    cin >> n >> k;
    vector <int> q(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        q[i]--;
    }   

    bool cyc = 1;
    for (int i = 0; i < n; ++i) {
        cyc &= q[q[i]] == i;
    }   

    vector <int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        s[i]--;
    }   

    bool c = 1;
    for (int i = 0; i < n; ++i)
        c &= s[i] == i;
    if (c) {
        cout << "NO" << endl;
        exit(0);
    }   
    for (int i = 0; i <= k; ++i) {
        int j = k - i;

        vector <int> cur(n);
        for (int p = 0; p < n; ++p)
            cur[p] = p;

        vector <vector <int> > d = {cur};

        for (int a = 0; a < i; ++a) {
        vector <int> ncur(n);
        for (int p = 0; p < n; ++p) {
            ncur[p] = cur[q[p]];                            
        }       
        cur = ncur;
        d.app(cur);
        }
        for (int a = 0; a < j; ++a) {
        vector <int> ncur(n);
        for (int p = 0; p < n; ++p) {
            ncur[q[p]] = cur[p];                           
        }       
        cur = ncur;
        d.app(cur);
        }
        
        if (cur == s) {

            bool ban = 0;
            if (cyc) {
            for (int i = 0; i + 1 < d.size(); ++i)
                if (d[i] == s)
                    ban = 1;
            }

            if (!ban) {
            cout << "YES" << endl;
            exit(0);
            }
        }   
    }
    cout << "NO" << endl;
}