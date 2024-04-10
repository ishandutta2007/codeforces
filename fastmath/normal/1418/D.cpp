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

    int n, q;
    cin >> n >> q;
    set <int> s;
    multiset <int> di;

    //init di

    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }   
    sort(all(a));
    for (int i = 0; i + 1 < a.size(); ++i)
        di.insert(a[i + 1] - a[i]);

        if (s.size() <= 2) {
            cout << 0 << endl;
        }   
        else {
            cout << *s.rbegin() - *s.begin() - *di.rbegin() << endl;
        }   

    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            auto it = s.find(x);
            if (it != s.begin()) {
                auto l = prev(it);
                di.erase(di.find(*it - *l));
            }   
            if (next(it) != s.end()) {
                auto r = next(it);
                di.erase(di.find(*r - *it));
            }   
            if (it != s.begin() && next(it) != s.end()) {
                auto l = prev(it);
                auto r = next(it);
                di.insert(*r - *l);
            }
            s.erase(x);
        }   
        else {
            s.insert(x);
            auto it = s.find(x);
            if (it != s.begin()) {
                auto l = prev(it);
                di.insert(*it - *l);
            }   
            if (next(it) != s.end()) {
                auto r = next(it);
                di.insert(*r - *it);
            }   
            if (it != s.begin() && next(it) != s.end()) {
                auto l = prev(it);
                auto r = next(it);
                di.erase(di.find(*r - *l));
            }
        }   

        if (s.size() <= 2) {
            cout << 0 << endl;
        }   
        else {
            cout << *s.rbegin() - *s.begin() - *di.rbegin() << endl;
        }   
    }   
    

}