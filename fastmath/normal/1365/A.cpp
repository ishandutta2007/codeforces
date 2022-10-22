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

const int N = 207;
int n, m;
bool a[N][N];
void solve() {
    cin >> n >> m;
    vector <bool> row(n), col(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j]) {
                row[i] = col[j] = 1;
            }   
        }   
    }
    int h1 = 0, h2 = 0;
    for (int i = 0; i < n; ++i)
        h1 += !row[i];
    for (int i = 0; i < m; ++i)
        h2 += !col[i];
    int h = min(h1, h2);
    if (h & 1)
        cout << "Ashish" << endl;
    else
        cout << "Vivek" << endl;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--)
        solve();

}