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

int n, h, m, k;

signed main() {
    #ifdef HOME                                                                                           
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> n >> h >> m >> k;
    vector <int> a(n), b(n);

    vector <ii> sc;

    int hal = m/2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];

        int t = a[i] * m + b[i];

        t %= hal;

        if (t + k <= hal) {
            sc.app(mp(t+1, 1));
            sc.app(mp(t + k, -1));

            //cout << i + 1 << " : " << t + 1 << ' ' << t + k << endl;
             
        }   
        else {
            sc.app(mp(t+1, 1));
            sc.app(mp(0, 1));
            sc.app(mp((t + k) % hal, -1));

            //cout << i + 1 << " : " << t + 1 << ' ' << 0 << ' ' << t + k << endl;

        }   

    }

    sort(all(sc));


    int mn = n+1;
    int cur = 0;
    int l = 0;

    int opt = -1;

    while (l < sc.size()) {
        int r = l;
        while (r < sc.size() && sc[r].f == sc[l].f) {
            cur += sc[r].s;
            ++r;
        }
    
        //debug(sc[l].f);
        //debug(cur);

        if (cur < mn) {
            mn = cur;
            opt = sc[l].f;
        }   
        l = r;
    }   

    assert(opt != -1);

    opt %= hal;

    cout << mn << ' ' << opt << endl;
    for (int i = 0; i < n; ++i) {
        int t = a[i] * m + b[i];
        t %= hal;

        if (t + k <= hal) {
            if (t < opt && opt < t + k)
                cout << i + 1 << ' ';
        }   
        else {
            if (t < opt || opt < (t + k) % hal)
                cout << i + 1 << endl;
        }                       
    }   
    cout << endl;
}