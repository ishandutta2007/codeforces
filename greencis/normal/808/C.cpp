#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

int n, w;
pair<pii, int> a[105];

int comp(pair<pii, int> a, pair<pii, int> b) { return a.second < b.second; }

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> w;
    for (int i = 0; i < n; ++i)
        cin >> a[i].first.first, a[i].second = i;
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        a[i].first.second = (a[i].first.first + 1) / 2, w -= a[i].first.second;
    if (w < 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = n - 1; i >= 0; --i) {
        int add = min(w, a[i].first.first - a[i].first.second);
        a[i].first.second += add;
        w -= add;
    }
    sort(a, a + n, comp);
    for (int i = 0; i < n; ++i)
        cout << a[i].first.second << " ";

    return 0;
}