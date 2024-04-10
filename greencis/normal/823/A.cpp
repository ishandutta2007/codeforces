#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k;
vector<pii> ansv;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    vector<pii> v;
    for (int i = 0; i < k; ++i) {
        v.push_back(make_pair(i + 2, 1));
        ansv.push_back(make_pair(1, i + 2));
    }

    int ans = 2;
    int curi = 0;
    for (int i = k + 2; i <= n; ++i) {
        ++v[curi].second;
        ans = max(ans, v[curi].second + v[curi == 0 ? 1 : 0].second);
        ansv.push_back(make_pair(v[curi].first, i));
        v[curi].first = i;
        ++curi %= v.size();
    }

    cout << ans << "\n";
    for (int i = 0; i < ansv.size(); ++i)
        cout << ansv[i].first << " " << ansv[i].second << "\n";

    return 0;
}