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
signed main() {
    int n;
    cin >> n;
    vector <int> mask;
    for (int i = 0; i < (1 << 13); ++i) {
        if (bp(i) == 6) {
            mask.app(i);
        }   
    }   
    auto quer = [](vector <int> a) {
        if (a.empty())
            return 0ll;
        cout << "? ";
        cout << a.size() << ' ';
        for (auto e : a)
            cout << e << ' ';
        cout << endl;
        fflush(stdout);
        int ans; cin >> ans;
        return ans;
    };
    vector <int> bit;
    for (int i = 0; i < 13; ++i) {
        vector <int> q;
        for (int j = 0; j < n; ++j) {
            if ((mask[j] >> i) & 1) {
                q.app(j + 1);
            }   
        }   
        bit.app(quer(q));
    }   
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int b = 0; b < 13; ++b) {
            if (!((mask[i] >> b) & 1)) {
                ans |= bit[b];
            }   
        }   
        cout << ans << ' ';
    }                      
    cout << endl;
}