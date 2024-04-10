#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[5005], cnt[5005], ans[5005];
int mx, mxi;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5005; ++j)
            cnt[j] = 0;
        mx = mxi = 0;
        for (int j = i; j < n; ++j) {
            ++cnt[a[j]];
            if (cnt[a[j]] > mx || cnt[a[j]] == mx && a[j] < mxi) {
                mx = cnt[a[j]];
                mxi = a[j];
            }
            ++ans[mxi];
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i + 1] << " ";

    return 0;
}