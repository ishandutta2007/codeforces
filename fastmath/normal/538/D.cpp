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

const int N = 207;
bool ban[2 * N][2 * N];
string a[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '.') {

                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < n; ++y) {
                        if (a[x][y] == 'o') {
                            int dx = i - x;
                            int dy = j - y;
                            ban[dx + N][dy + N] = 1;
                        }   
                    }   
                }   

            }   
        }   
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 'x') {

                bool can = 0;
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < n; ++y) {
                        if (a[x][y] == 'o') {
                            int dx = i - x;
                            int dy = j - y;
                            can |= !ban[dx + N][dy + N];
                        }   
                    }   
                }   
                if (!can) {
                    cout << "NO\n";
                    exit(0);
                }   
            }   
        }   
    }
    cout << "YES\n";
    for (int i = -n + 1; i < n; ++i) {
        for (int j = -n + 1; j < n; ++j) {
            if (i == 0 && j == 0)
                cout << 'o';
            else if (ban[i + N][j + N])
                cout << '.';
            else
                cout << 'x';
        }   
        cout << '\n';
    }   
}