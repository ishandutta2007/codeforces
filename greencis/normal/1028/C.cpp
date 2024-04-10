#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int maxn = 150000;
int n, xa[maxn], ya[maxn], xb[maxn], yb[maxn];
int mxl_pref[maxn], mxl_suff[maxn];
int mnr_pref[maxn], mnr_suff[maxn];
int mxu_pref[maxn], mxu_suff[maxn];
int mnd_pref[maxn], mnd_suff[maxn];


int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
    mxl_pref[0] = xa[0];
    mnr_pref[0] = xb[0];
    mxu_pref[0] = ya[0];
    mnd_pref[0] = yb[0];
    for (int i = 1; i < n; ++i) {
        mxl_pref[i] = max(mxl_pref[i - 1], xa[i]);
        mnr_pref[i] = min(mnr_pref[i - 1], xb[i]);
        mxu_pref[i] = max(mxu_pref[i - 1], ya[i]);
        mnd_pref[i] = min(mnd_pref[i - 1], yb[i]);
    }

    mxl_suff[n-1] = xa[n-1];
    mnr_suff[n-1] = xb[n-1];
    mxu_suff[n-1] = ya[n-1];
    mnd_suff[n-1] = yb[n-1];
    for (int i = n - 2; i >= 0; --i) {
        mxl_suff[i] = max(mxl_suff[i + 1], xa[i]);
        mnr_suff[i] = min(mnr_suff[i + 1], xb[i]);
        mxu_suff[i] = max(mxu_suff[i + 1], ya[i]);
        mnd_suff[i] = min(mnd_suff[i + 1], yb[i]);
    }

    if (mxl_suff[1] <= mnr_suff[1] && mxu_suff[1] <= mnd_suff[1]) {
        cout << mxl_suff[1] << " " << mxu_suff[1];
        return 0;
    }
    if (mxl_pref[n - 2] <= mnr_pref[n - 2] && mxu_pref[n - 2] <= mnd_pref[n - 2]) {
        cout << mxl_pref[n - 2] << " " << mxu_pref[n - 2];
        return 0;
    }
    for (int i = 1; i <= n - 2; ++i) {
        int l = max(mxl_suff[i + 1], mxl_pref[i - 1]);
        int r = min(mnr_suff[i + 1], mnr_pref[i - 1]);
        int u = max(mxu_suff[i + 1], mxu_pref[i - 1]);
        int d = min(mnd_suff[i + 1], mnd_pref[i - 1]);
        if (l <= r && u <= d) {
            cout << l << " " << u;
            return 0;
        }
    }
}