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
const int N = 1e5 + 7;
int n, m, k;
set <int> mx[N], my[N];
void solve(int t) {
    int lx = 1, rx = n + 1, ly = 0, ry = m + 1;
    int x = 1, y = 1, sum = 1;
    while (1) {
        if (t == 0) {
            if (y == ry) break;
            int y1 = ry - 1;
            auto t = mx[x].upper_bound(y);
            if (t != mx[x].end()) y1 = min(y1, *t - 1);
            if (y == y1) break;
            sum += abs(y1 - y);
            ry = y = y1;
        }
        else if (t == 1) {
            if (x == rx) break;
            int x1 = rx - 1;
            auto t = my[y].upper_bound(x);
            if (t != my[y].end()) x1 = min(x1, *t - 1);
            if (x == x1) break;
            sum += abs(x1 - x);
            rx = x = x1;
        }
        else if (t == 2) {
            if (y == ly) break;
            int y1 = ly + 1;
            auto t = mx[x].lower_bound(y); 
            if (t != mx[x].begin()) {
                --t; 
                y1 = max(y1, *t + 1);
            }   
            if (y == y1) break;
            sum += abs(y1 - y);
            ly = y = y1;
        }
        else {
            if (x == lx) break;
            int x1 = lx + 1;
            auto t = my[y].lower_bound(x);
            if (t != my[y].begin()) {
                --t;
                x1 = max(x1, *t + 1);
            }   
            if (x == x1) break;
            sum += abs(x1 - x);
            lx = x = x1;
        }   
        t = (t + 1) % 4;
    }   
    if (sum == n * m - k) {
        cout << "Yes\n";
        exit(0);
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int x, y; cin >> x >> y;
        mx[x].insert(y); my[y].insert(x);
    }       
    solve(0); solve(1);
    cout << "No\n";
}