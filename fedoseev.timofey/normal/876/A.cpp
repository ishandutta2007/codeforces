# include <iostream>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (n == 1) cout << 0 << endl;
    else {
        if (b <= a && b <= c) cout << (n - 1) * b << endl;
        else if (a <= c) cout << (n - 1) * a << endl;
        else cout << min(a, b) + (n - 2) * c << endl;
    }
}