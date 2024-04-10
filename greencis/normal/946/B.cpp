#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    while (true) {
        if (!a || !b) break;
        if (a >= 2 * b) a %= 2 * b;
        else if (b >= 2 * a) b %= 2 * a;
        else break;
    }
    cout << a << " " << b << endl;
}