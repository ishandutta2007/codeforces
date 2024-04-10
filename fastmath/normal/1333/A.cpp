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
const int N = 501;
char ans[N][N];
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
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) % 2 == 0)
                    ans[i][j] = 'B';
                else
                    ans[i][j] = 'W';
            }   
        }   
        if ((n * m) % 2 == 0) {
            ans[0][1] = 'B';
        }   
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) 
                cout << ans[i][j];
            cout << endl;
        }   
    }   

}