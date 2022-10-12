#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 105;
int r[N][N], n;
int px = 0, py = 0;
int qx = 0, qy = 1;

void applyp(int a) {
    r[px][py] = a;
    cout << a << " " << px+1 << " " << py+1 << endl;
    py += 2;
    if (py >= n) {
        px++;
        if ((px)&1) py = 1;
        else py = 0;
    }
}

void applyq(int a) {
    r[qx][qy] = a;
    cout << a << " " << qx+1 << " " << qy+1 << endl;
    qy += 2;
    if (qy >= n) {
        qx++;
        if ((qx)&1) qy = 0;
        else qy = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int t = 0; t < n*n; t++) {
        int a; cin >> a;
        if (a != 1 && px < n && py < n) {
            applyp(1);
        } else if (a != 2 && qx < n && qy < n) {
            applyq(2);
        } else {
            if (px >= n || py >= n) {
                if (a == 2) applyq(3);
                else applyq(2);
            } else {
                if (a == 1) applyp(3);
                else applyp(1);
            }
        }
    }
    for (int i = 0; i < n; i++)
        debug(vector(r[i], r[i]+n));
}