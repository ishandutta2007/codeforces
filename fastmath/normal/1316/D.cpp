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

const int N = 1007;
ii a[N][N];
bool used[N][N];

char ans[N][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    queue <ii> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j].f >> a[i][j].s;
            if (a[i][j].f == i && a[i][j].s == j) {
                q.push(mp(i, j));
                used[i][j] = 1;
                ans[i][j] = 'X';
            }   
        }   
    }   
    vector <ii> v = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    vector <char> t = {'U', 'D', 'L', 'R'};
    vector <char> rev = {'D', 'U', 'R', 'L'};
    while (q.size()) {
        auto p = q.front();
        q.pop();
        for (int tp = 0; tp < 4; ++tp) {
            auto e = v[tp];
            int i = p.f + e.f, j = p.s + e.s;
            if (1 <= i && i <= n && 1 <= j && j <= n) {
                if (!used[i][j] && a[i][j] == a[p.f][p.s]) {
                    q.push(mp(i, j));
                    used[i][j] = 1;
                    ans[i][j] = rev[tp];
                }   
            }   
        }   
    }   
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j].f != -1 && !used[i][j]) {
                cout << "INVALID" << endl;
                exit(0);
            }   
            if (a[i][j].f == -1) {
                for (int tp = 0; tp < 4; ++tp) {
                    auto e = v[tp];
                    int x = i + e.f, y = j + e.s;
                    if (1 <= x && x <= n && 1 <= y && y <= n) {
                        if (a[x][y].f == -1) {
                            ans[i][j] = t[tp];
                            break;
                        }   
                    }   
                }   
                if (ans[i][j] == 0) {
                    cout << "INVALID" << endl;
                    exit(0);
                }   
            }   
        }   
    }        
    cout << "VALID" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << ans[i][j];
        }   
        cout << endl;
    }   
}