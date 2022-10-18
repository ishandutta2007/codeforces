#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, ax, ay, bx, by, cx, cy;

int get(int x, int y) {
    if (x > 0 && y > 0) {
        return 0;
    }
    if (x > 0 && y < 0) {
        y = -y;
        return 2;
    }
    if (x < 0 && y > 0) {
        x = -x;
        return 4;
    }
    if (x < 0 && y < 0) {
        x = -x;
        y = -y;
        return 6;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    bx -= ax;
    by -= ay;
    cx -= ax;
    cy -= ay;
    int bi = get(bx, by);
    int ci = get(cx, cy);
    cout << (bi == ci ? "YES" : "NO") << endl;
}