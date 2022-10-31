#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], ip[MN];
vector<pair<int, int>> ch;

void myswap(int &i, int j) {
    ch.emplace_back(i + 1, j + 1);
    swap(ip[a[i]-1], ip[a[j]-1]);
    swap(a[i], a[j]);
    i = j;
}

void solve(int a, int b) {
    if(a == b) return;
    if(a < n / 2) myswap(a,  n - 1);
    else myswap(a, 0);

    if(abs(a - b) < n / 2) {
        if(a < n / 2) myswap(a, n - 1);
        else myswap(a, 0);
    }

    myswap(a, b);
}

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ip[a[i]-1] = i;
    }

    for(int d = 0; d < n / 2; d++) {
        solve(ip[n / 2 - d - 1], n / 2 - d - 1);
        solve(ip[n / 2 + d], n / 2 + d);
    }

    printf("%d\n", ch.size());
    for(auto tt : ch) {
        printf("%d %d\n", tt.first, tt.second);
    }

    assert(ch.size() <= 5 * n);
    assert(is_sorted(a, a + n));
    return 0;
}