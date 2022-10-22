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

mt19937 rnd(2007);
void solve() {
    int n, k;
    cin >> n >> k;

    int mx = 1;

    #ifdef HOME
    const int T = 5;
    #else
    const int T = 29;
    #endif

    for (int q = 0; q < T; ++q) {
        int i = mx;
        while (i == mx) {
            i = rnd() % n + 1;
        }   
        cout << "? 1 1" << endl;
        cout << mx << endl;
        cout << i << endl;
        fflush(stdout);
        string ans;
        cin >> ans;
        if (ans == "SECOND")
            mx = i;
    }   

    if (mx != 1) {
        cout << "? 1 1" << endl;
        cout << mx << endl;
        cout << 1 << endl;
        fflush(stdout);
        string ans;
        cin >> ans;
        if (ans != "EQUAL") {
            cout << "! 1" << endl;
            fflush(stdout);
            return;
        }   
    }   

    vector <int> pref = {1};
    int p = 0;
    for (; ; ++p) {
        vector <int> add;
        for (int j = (1 << p) + 1; j <= (1 << p) + (1 << p); ++j)
            add.app(j);

        if (add.back() > n) {
            break;
        }   

        cout << "? " << (1 << p) << ' ' << (1 << p) << endl;
        for (int e : pref)
            cout << e << ' ';
        cout << endl;
        for (int e : add)
            cout << e << ' ';
        cout << endl;
        fflush(stdout);

        string ans;
        cin >> ans;

        if (ans != "EQUAL")
            break;

        for (int e : add)
            pref.app(e);
    }   
    
    for (p = p - 1; p >= 0; --p) {
        vector <int> add;
        for (int j = pref.size() + 1; j <= pref.size() + (1 << p); ++j)
            add.app(j);
        if (add.back() > n)
            continue;
        cout << "? " << (1 << p) << ' ' << (1 << p) << endl;
        for (int i = 0; i < (1 << p); ++i)
            cout << pref[i] << ' ';
        cout << endl;
        for (int e : add)
            cout << e << ' ';
        cout << endl;
        fflush(stdout);

        string ans;
        cin >> ans;
        if (ans != "EQUAL")
            continue;

        for (int e : add)
            pref.app(e);
    }   

    cout << "! " << pref.size() + 1 << endl;
    fflush(stdout);
}   

signed main() {

    int t;
    cin >> t;
    while (t--) 
        solve();

}