#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int g = __gcd(a, b);
        cout << (g != 1 ? "Infinite" : "Finite") << endl;
    }
}