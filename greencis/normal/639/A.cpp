#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n, k, q, t[200105], x, y;
vector<pii> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> q;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    while (q--)
    {
        cin >> x >> y;
        --y;
        if (x == 1) {
            v.push_back(make_pair(t[y], y));
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            while (v.size() > k)
                v.pop_back();
        } else {
            int g = 0;
            for (int i = 0; i < v.size(); ++i)
                g |= v[i].second == y;
            if (g) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}