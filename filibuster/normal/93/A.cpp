#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 311;


mt19937 rnd(0);

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    a--;
//    b--;

    if(a % m == 0 && (b % m == 0 || b == n) || a / m == (b - 1) / m) {
        cout << 1 << endl;
    } else if((b - a) % m == 0 || a % m == 0 || b % m == 0 || b == n || a / m + 1 == (b - 1) / m) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
}