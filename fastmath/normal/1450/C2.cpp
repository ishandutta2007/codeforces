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
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    #define x first
    #define y second
    while (t--) {
        int n;
        cin >> n;
        vector <vector <ii> > px(3), po(3);
        vector <string> a(n);
        int k = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == 'X') {
                    int rem = (i + j) % 3;
                    px[rem].app(mp(i, j));
                    k++;
                }   
                else if (a[i][j] == 'O') {
                    int rem = (i + j) % 3;
                    po[rem].app(mp(i, j));
                    k++;
                }   
            }
        }   

        auto f = [&] () {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (i == j)
                        continue;
                    if (px[i].size() + po[j].size() <= k/3) {
                        for (auto e : px[i])
                            a[e.x][e.y] = 'O';
                        for (auto e : po[j])
                            a[e.x][e.y] = 'X';
                        return;
                    }   
                }   
            }   
        };

        f();

        for (auto e : a)
            cout << e << endl;
    }   
}