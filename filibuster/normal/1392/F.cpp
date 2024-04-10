#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e6 + 13;

mt19937 rnd(0);
li a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    li sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    li l = 0, r = 2e12;
    while(r - l > 1) {
        li m = (l + r) / 2;

        if(n * 1ll * (n - 1) / 2 + n * m > sum)
            r = m;
        else
            l = m;
    }

    li d = sum - n * 1ll * (n - 1) / 2 - n * l;
    for(int i = 0; i < n; i++) {
        cout << l + i + (i < d) << ' ';
    }
}