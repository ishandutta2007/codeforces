#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef uint64_t ull;
typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, c[105], a[105][105];
int revy[10005], revx[10005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) cin >> c[i], sum += c[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < c[i]; ++j) {
            cin >> a[i][j];
            revy[a[i][j]] = i;
            revx[a[i][j]] = j;
        }
    }
    int x = 0, y = 0;
    vector<pair<pii, pii>> v;
    for (int i = 1; i <= sum; ++i, ++x, x >= c[y] ? x = 0, ++y : 1) {
        int ny = revy[i];
        int nx = revx[i];
        if (x == nx && y == ny) continue;
        v.push_back({{y, x}, {ny, nx}});
        swap(revx[a[y][x]], revx[i]);
        swap(revy[a[y][x]], revy[i]);
        swap(a[y][x], a[ny][nx]);
    }
    cout << v.size() << endl;
    for (auto& p : v)
        cout << p.first.first+1 << " " << p.first.second+1 << " " << p.second.first+1 << " " << p.second.second+1 << "\n";
}