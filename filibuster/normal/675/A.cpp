#include <bits/stdc++.h>

#define x first
#define y second
#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e5 + 13;


/*

*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    if(c < 0) {
        c = -c;
        swap(a, b);
    }

    if(c != 0)
        cout << (b >= a && (b - a) % c == 0 ? "YES" : "NO") << endl;
    else
        cout << (b == a ? "YES" : "NO") << endl;
}