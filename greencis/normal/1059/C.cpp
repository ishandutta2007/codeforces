#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<int> v;

void solve(int n, int mul) {
    if (n == 1) {
        v.push_back(mul);
        return;
    }
    int i = 2;
    for (; n / i <= n / (i + 1); ++i);
    for (int j = 0; j < n - n / i; ++j)
        v.push_back(mul);
    solve(n / i, mul * i);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    solve(n, 1);
    for (int x : v) cout << x << " ";
}