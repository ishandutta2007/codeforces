#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;


/*
4 5
0 1
1 2
2 3
3 4

1 6
4 4
*/

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a;
    for(int i = k + 1; i <= n; i++) {
        a.push_back(i);
    }

    for(int i = k - 1; i > (k - 1) / 2; i--) {
        a.push_back(i);
    }

    cout << a.size() << endl;
    for(auto x : a)
        cout << x << ' ';
    cout << endl;
}

int main() {


    int t = 1;
    cin >> t;

    while(t--)
        solve();
}