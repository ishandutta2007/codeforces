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

const int N = 307;
bool ans[N][N];

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

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans[i][j] = 0;

        vector <ii> ord;
        for (int sh = 0; sh < n; ++sh)
            for (int i = 0; i < n; ++i)
                ord.app(mp(i, (i+sh)%n));

        for (int i = 0; i < k; ++i) {
            ans[ord[i].f][ord[i].s] = 1;
        }   

        int maxr = 0, minr = n;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j)
                sum += ans[i][j];
            maxr = max(maxr, sum);
            minr = min(minr, sum);                
        }   

        int maxc = 0, minc = n;
        for (int j = 0; j < n; ++j) {
            int sum = 0;
            for (int i = 0; i < n; ++i)
                sum += ans[i][j];
            maxc = max(maxc, sum);
            minc = min(minc, sum);                            
        }
        
        cout << (maxr - minr) * (maxr - minr) + (maxc - minc) * (maxc - minc) << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << ans[i][j];
            cout << endl;
        }   
    }

}