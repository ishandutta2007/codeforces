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

    vector <int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }   

    vector <ii> ans;

    int ptr = n;
    vector <ii> v[4];
    for (int i = n; i; --i) {
        if (a[i] == 0) {
            
        }   
        else if (a[i] == 1) {
            ans.app(mp(ptr, i));
            v[1].app(mp(ptr, i));
            ptr--;
        }   
        else if (a[i] == 2) {
            if (v[1].empty()) {
                cout << -1 << endl;
                exit(0);
            }   
            else {
                v[2].app(mp(v[1].back().f, i));
                ans.app(mp(v[1].back().f, i));
                v[1].pop_back();
            }   
        }   
        else {
            assert(a[i] == 3);
            auto t = mp(ptr, i);
            if (v[3].size()) {
                ans.app(mp(ptr, i));
                ans.app(mp(ptr, v[3].back().s));
                v[3].pop_back();
                ptr--;                
            }   
            else if (v[2].size()) {
                ans.app(mp(ptr, i));
                ans.app(mp(ptr, v[2].back().s));
                v[2].pop_back();
                ptr--;
            }
            else if (v[1].size()) {
                ans.app(mp(ptr, i));
                ans.app(mp(ptr, v[1].back().s));
                v[1].pop_back();                
                ptr--;
            }   
            else {
                cout << -1 << endl;
                exit(0);
            }   
            v[3].app(t);
        }   
    }   
    
    cout << ans.size() << endl;
    for (auto e : ans) {
        cout << e.f << ' ' << e.s << endl;
    }   
}