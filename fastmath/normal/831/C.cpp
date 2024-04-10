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
    int n, k;
    cin >> k >> n;
    vector <int> a(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }   

    /*
    for (int i = 1; i <= k; ++i)
        cout << a[i] << ' ';
    cout << endl;
    */

    vector <int> b(n);
    map <int, int> d;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        ++d[b[i]];
    }

    set <int> ms;
    for (int i = 1; i <= k; ++i) {
        ms.insert(b[0] - a[i]);
    }   

    int ans = 0;
    for (int sh : ms) {
        //cout << "sh " << sh << endl;
        map <int, int> dd;
        for (int i = 1; i <= k; ++i)
            ++dd[a[i] + sh];
        int ban = 0;
        for (auto e : d) {
            if (dd[e.f] < e.s) {
                ban = 1;
                break;
            }
        }               
        ans += !ban;
    }   
    cout << ans << endl;                    
}