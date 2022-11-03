#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 3e5 + 13;
const int B = 400;

int a[N];
li s[N];
pair<pii, int> b[N];
li ans[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

//    for(int i = 1; i < B; i++) {
//        for(int j = n - 1; j >= 0; j--) {
//            s[i][j] = (j + i < n ? s[i][i + j] : 0) + a[j];
//        }
//    }

//    for(int i = 1; i <= 3; i++) {
//        cout << i << ": ";
//        for(int j = 0; j < n; j++) {
//            cout << s[i][j] << ' ';
//        }
//        cout << endl;
//    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        x--;

        b[i] = make_pair(make_pair(y, x), i);

//        if(y < B) {
////            cout << x << ' ' << y << ' ' << s[y][x] << endl;
//            cout << s[y][x] << '\n';
//        } else {
//            li res = 0;
//            for(int j = x; j < n; j += y) {
//                res += a[j];
//            }
//            cout << res << '\n';
//        }
    }

    sort(b, b + q);

    int cur = 0;
    for(int i = 0; i < q; i++) {
        int x = b[i].f.s;
        int y = b[i].f.f;

        if(y == cur) {
            ans[b[i].s] = s[x];
        } else if(y < B) {
            for(int j = n - 1; j >= 0; j--) {
                s[j] = (j + y < n ? s[j + y] : 0) + a[j];
            }
            ans[b[i].s] = s[x];
            cur = y;
        } else {
            li res = 0;
            for(int j = x; j < n; j += y) {
                res += a[j];
            }
            ans[b[i].s] = res;
        }
    }

    for(int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}