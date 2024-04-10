#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k;
ll sum_cycle, sumc, wasc, c[100105];
set<int> was;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> c[i], sumc += c[i];
    for (int i = 1; i < n; ++i)
        sum_cycle += c[i] * c[i + 1];
    sum_cycle += c[n] * c[1];
    while (k--) {
        int x;
        cin >> x;
        ll cur = sumc - c[x] - wasc;
        if (was.find((x + n - 2) % n + 1) == was.end())
            cur -= c[(x + n - 2) % n + 1];
        if (was.find(x % n + 1) == was.end())
            cur -= c[x % n + 1];
        sum_cycle += c[x] * cur;
        was.insert(x);
        wasc += c[x];
    }
    cout << sum_cycle << endl;

    return 0;
}