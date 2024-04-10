#include <iostream>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);

    int N, X0, Y0;
    cin >> N >> X0 >> Y0;

    set< pair<int, int> > S;
    for (int i = 0; i < N; ++i) {
        int X, Y; cin >> X >> Y;
        int dx = X - X0;
        int dy = Y - Y0;
        int d = gcd(dx, dy);
        dx /= d;
        dy /= d;
        if (dy < 0) {
            dy = -dy;
            dx = -dx;
        }
        if (dx == 0)
            dy = 1;
        S.insert(make_pair(dx, dy));
    }

    cout << S.size() << "\n";
}