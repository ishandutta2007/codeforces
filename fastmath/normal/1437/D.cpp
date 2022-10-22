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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int p = 1, cur = 0, r = 0, h = 1;
        for (int i = 1; i < n; ++i) {
            int u = a[i];
            if (u > r) {
                r = u;
                cur++;
            }   
            else {
                p--;
                if (p) {
                    r = u;
                    cur++;
                }   
                else {
                    p = cur;
                    cur = 1;
                    r = u;
                    h++;
                }   
            }   
            /*                            
            debug(i);
            debug(h);
            debug(r);
            debug(p);
            */                    
        }
        cout << h << endl;

    }   
}