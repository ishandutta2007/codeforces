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

const int N = 107;
int a[N][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }   
        }   
        int ans = 0;
        for (int i = 0; i < (n + 1) / 2; ++i) {
            for (int j = 0; j < (m + 1) / 2; ++j) {
                int ri = n - i - 1;
                int rj = m - j - 1;

                vector <int> x = {i};
                if (i != ri)
                    x.app(ri);

                vector <int> y = {j};
                if (j != rj)
                    y.app(rj);

                vector <int> c;
                for (int xx : x) {
                    for (int yy : y) {
                        c.app(a[xx][yy]);
                    }   
                }   

                sort(all(c));
                int mid = c.size()/2;
                int to = c[mid];

                for (auto e : c)
                    ans += abs(e - to);
            }   
        }   
        cout << ans << endl;
    }   

}