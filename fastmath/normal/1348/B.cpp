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
        int n, k;
        cin >> n >> k;
        set <int> ms;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ms.insert(x);
        }   
        if (ms.size() > k) {
            cout << "-1" << endl;
        }   
        else {

            for (int x = 1; x <= 100; ++x) {
                if (ms.size() < k && ms.find(x) == ms.end()) {
                    ms.insert(x);
                }   
            }   
            vector <int> a;
            for (int e : ms)
                a.app(e);

            cout << k * 100 << endl;
            for (int i = 0; i < 100; ++i) {
                for (int e : a)
                    cout << e << ' ';
            }   
            cout << endl;
        }   
    }   

}