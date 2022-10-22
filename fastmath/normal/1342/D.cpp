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

const int N = 2e5 + 7;
vector <int> p[N];

struct Comp {
    bool const operator () (const int i, const int j) const {
        return (p[i].size() < p[j].size()) || (p[i].size() == p[j].size() && i < j);
    }   
};

int mx[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a)); reverse(all(a));
    for (int i = 1; i <= k; ++i)
        cin >> mx[i];

    set <int, Comp> ms;
    int ans = 0;
    for (int x : a) {
        /*
        cout << "add " << x << endl;
        if (ms.size())
            cout << p[*ms.begin()].size() << ' ' << mx[x] << endl;
        */
        if (ms.empty() || p[*ms.begin()].size() == mx[x]) {
            //cout << "insert " << ans << endl;
            ms.insert(ans);
            ++ans;
        }   
        int to = *ms.begin();
        ms.erase(to);
        p[to].app(x);
        ms.insert(to);
    }   

    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        cout << p[i].size() << ' ';
        for (int e : p[i])
            cout << e << ' ';
        cout << endl;
    }   
        
}