#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int A = 513;

int di[] = {0, 1, -1, 0};
int dj[] = {1, 0, 0, -1};
/*
*/

mt19937 rnd(5443);

li a[N];

void solve() {
    int n;
    cin >> n;

    int i = upper_bound(a, a + N, n) - a;

    cout << i << endl;
}

int main() {
    for(int i = 3; (i - 3) / 2 < N; i += 2) {
        int j = (i - 3) / 2;
        a[j] = (i * 1ll * i - 1) / 2 + 1;
    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}