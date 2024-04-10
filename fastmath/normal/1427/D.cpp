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
    vector <int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }   

    vector <vector <int> > ans;

    while (1) {
        vector <int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[p[i]] = i;
        }   
        int v = -1;
        for (int x = 0; x + 1 < n; ++x) {
            if (pos[x + 1] < pos[x]) {
                v = x;
                break;
            }   
        }                       
        if (v == -1)
            break;
        int x = v;

        int l = pos[x];
        while (p[l - 1] == p[l] - 1) {
            l--;
        }   
        assert(l > pos[x + 1]);

        vector <int> op;
        if (pos[x + 1]) {
            op.app(pos[x + 1]);
        }   
        op.app(l - pos[x + 1]);
        op.app(pos[x] - l + 1);
        if (pos[x] < n - 1) {   
            op.app(n - pos[x] - 1);
        }

        ans.app(op);

        vector <int> np;
        for (int i = pos[v] + 1; i < n; ++i) {
            np.app(p[i]);
        }   
        for (int i = l; i <= pos[x]; ++i) 
            np.app(p[i]);
        for (int i = pos[x + 1]; i < l; ++i)
            np.app(p[i]);
        for (int i = 0; i < pos[x + 1]; ++i)
            np.app(p[i]);
        p = np;
    }   
    cout << ans.size() << endl;
    for (auto v : ans) {
        cout << v.size() << ' ';
        for (auto e : v)
            cout << e << ' ';
        cout << endl;                    
    }   
}