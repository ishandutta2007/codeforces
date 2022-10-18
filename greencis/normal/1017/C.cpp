#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[100105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    int ans = 1e9;
    int len = -1, groups = -1;
    for (int i = 1; i <= n; ++i) {
        int cur = (n % i == 0 ? i + n / i : n / i + 1 + i);
        if (cur < ans)
            ans = cur, len = i, groups = n / i;
    }
    int idx = 0;
    for (int i = len * groups + 1; i <= n; ++i)
        a[idx++] = i;
    for (int i = groups; i >= 1; --i) {
        for (int j = 1; j <= len; ++j)
            a[idx++] = (i - 1) * len + j;
    }
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    //cerr << endl << len << endl;
}