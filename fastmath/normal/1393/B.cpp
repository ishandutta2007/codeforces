#include<bits/stdc++.h>
using namespace std;
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;

    multiset <int> cnt;
    map <int, int> d;

    int sum = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++d[x];
    }   
    
    for (auto e : d) {
        cnt.insert(e.s);
        sum += e.s/2;
    }

    int q;
    cin >> q;
    while (q--) {
        char t;
        cin >> t;
        int x; cin >> x;

        bool was = d.find(x) != d.end();

        sum -= d[x]/2;
        if (was)
            cnt.erase(cnt.find(d[x]));

        if (t == '+') {
            ++d[x];
        }   
        else {
            --d[x];
        }   

        cnt.insert(d[x]);
        sum += d[x]/2;

        if (*cnt.rbegin() >= 4 && sum >= 4) {
            cout << "YES" << endl;
        }   
        else {
            cout << "NO" << endl;
        }   
    }   
}