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

void solve() {
    int n, k;
    cin >> n >> k;

    k--;

    if(n % 2 == 0) {
        cout << k % n + 1 << endl;
    } else {

        cout << (k + k / (n / 2)) % n + 1 << endl;
    }
}

int main() {


    int t = 1;
    cin >> t;

    while(t--)
        solve();
}