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

    int n;
    cin >> n;
    vector <ii> a(n);
    vector <int> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].f >> a[i].s;
        c.app(a[i].f);
        c.app(a[i].s);        
    }   

    int ans = 1e18;
    for (auto h : c) {
        bool ban = 0;
        int l = 0;
        vector <int> can;
        int w = 0;
        for (auto e : a) {
            if (e.f > h && e.s > h) {
                ban = 1;
            }   
            else if (e.s <= h) {
                w += e.f;
                if (e.s <= e.f && e.f <= h)
                    can.app(e.f - e.s);
            }
            else {
                l++;                                  
                w += e.s;
            }   
        }   
        if (!ban && l * 2 <= n) {            
            int mx = n/2;
            int ch = mx - l;

            sort(all(can));
            reverse(all(can));
            for (int i = 0; i < min(ch, (int)can.size()); ++i) {
                w -= can[i];
            }   
        
            //cout << h << ' ' << w << endl;
            
            ans = min(ans, w * h);
        }   
    }   
    cout << ans << endl;
}