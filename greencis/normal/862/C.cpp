#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, x, a[100105];

vector<int> solve(int n, int x) {
    if (n == 1)
        return {x};
    if (n == 2) {
        if (!x)
            return {};
        return {0, x};
    }
    if (n == 3) {
        return {x + 131072, 131072 + 131072 * 2, 131072 * 2};
    }
    if (n == 4) {
        return {x, 131072, 131072 * 2, 131072 + 131072 * 2};
    }
    if (n % 4 == 2 && !x) {
        vector<int> v = {1, 2, 4, 8, 16, 31};
        n -= 6;
        for (int i = 0; i < n; ++i)
            v.push_back(32 + i);
        return v;
    }
    vector<int> v = solve((n - 1) % 4 + 1, x);
    int lft = n - v.size();
    for (int i = 0; i < lft; ++i)
        v.push_back(131072 * 4 + i);
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> x;
    vector<int> v = solve(n, x);
    sort(v.begin(), v.end());
    if (v.size()) {
        cout << "YES" << endl;
        for (int x : v)
            cout << x << " ";
        cout << endl;
    } else
        cout << "NO" << endl;

    return 0;
}