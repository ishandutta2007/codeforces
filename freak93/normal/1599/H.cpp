#include <iostream>
#include <algorithm>

using namespace std;

static const int edge = 1000 * 1000 * 1000;
int main() {
    ios::sync_with_stdio(false);

    cout << "? 1 1" << endl;
    int a; cin >> a;

    cout << "? 1000000000 1" << endl;
    int b; cin >> b;

    cout << "? 1 1000000000" << endl;
    int c; cin >> c;

    cout << "? 1000000000 1000000000" << endl;
    int d; cin >> d;

    int mid = (1 + a + edge - b) / 2;

    auto ask = [&](int x) {
        if (x < 0 || x > edge)
            return 2 * edge + 5;
        cout << "? " << x << " 1" << endl;
        int y; cin >> y;
        return y;
    };

    int y1 = min({ask(mid - 1), ask(mid), ask(mid + 1)}) + 1;
    int x1 = (a + 2) - y1;
    int x2 = edge - b + (y1 - 1);
    int y2 = edge - c + (x1 - 1);

    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}