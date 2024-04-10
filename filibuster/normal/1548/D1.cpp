//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 6000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

pii a[N];
bitset<N> bs[N];
int deg[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int dx = abs(a[i].x - a[j].x);
            int dy = abs(a[i].y - a[j].y);
            int cnt = __gcd(dx, dy) - 1;

//            cout << "for " << i << ' '<< j << ' ' << cnt << endl;

            if(cnt % 4 == 3)
                bs[i][j] = bs[j][i] = 1;
        }
    }

    for(int i = 0; i < n; i++)
        deg[i] = bs[i].count();

    li ans1 = 0, ans3 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) if(bs[i][j]) {
//            cout << i << ' ' << j << ' ' << (bs[i] & bs[j]).count() << endl;
            ans3 += deg[i] - 1;
            ans1 += n - 1 - deg[i];
        }
    }

//    cout << ans1 << ' ' << ans3 << endl;

    cout << ans1 + ans3 / 3 << endl;
}