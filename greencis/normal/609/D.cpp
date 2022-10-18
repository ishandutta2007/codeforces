#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ll n,m,k,s,t,c,a[200105],b[200105];
vector< pair<ll, int> > gad[2];
vector< pii > ans;

bool f(int L) {
    ll mna = 9e18, mnb = 9e18;
    int mnai = -1, mnbi = -1;
    for (int i = 0; i <= L; ++i) {
        if (a[i] < mna) {
            mna = a[i];
            mnai = i;
        }
        if (b[i] < mnb) {
            mnb = b[i];
            mnbi = i;
        }
    }

    ll cursum = 0;
    ans.clear();
    int ai = 0, bi = 0;
    for (int i = 0; i < k; ++i) {
        if (bi >= gad[1].size() ||
            ai < gad[0].size() && mna * gad[0][ai].first <= mnb * gad[1][bi].first) {
            ans.push_back(make_pair(gad[0][ai].second, mnai));
            cursum += mna * gad[0][ai].first;
            ++ai;
        } else {
            ans.push_back(make_pair(gad[1][bi].second, mnbi));
            cursum += mnb * gad[1][bi].first;
            ++bi;
        }
        if (cursum > s) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k >> s;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < m; ++i) {
        cin >> t >> c;
        gad[t - 1].push_back(make_pair(c, i));
    }
    sort(gad[0].begin(), gad[0].end());
    sort(gad[1].begin(), gad[1].end());

    int L = 0, R = n - 1;
    while (L < R) {
        int mid = (L + R) >> 1;
        if (f(mid)) R = mid;
        else L = mid + 1;
    }
    if (L > R || !f(L)) { cout << -1; return 0; }
    cout << L + 1 << "\n";
    for (int i = 0; i < k; ++i)
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";

    return 0;
}