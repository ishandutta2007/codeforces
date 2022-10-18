#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, c, d;
pii fc[100105], fd[100105];
int mxc[100105], mxd[100105];
int ci, di;
int x, y;
char z[2];

int ans = 0;

int find_best_c(int x) {
    if (ci == 0)
        return -1;
    if (fc[0].first > x)
        return -1;
    int L = 0, R = ci - 1;
    while (L < R) {
        int mid = (L + R + 1) / 2;
        if (fc[mid].first <= x)
            L = mid;
        else
            R = mid - 1;
    }
    return L;
}

int find_best_d(int x) {
    if (di == 0)
        return -1;
    if (fd[0].first > x)
        return -1;
    int L = 0, R = di - 1;
    while (L < R) {
        int mid = (L + R + 1) / 2;
        if (fd[mid].first <= x)
            L = mid;
        else
            R = mid - 1;
    }
    return L;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> c >> d;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> z;
        if (*z == 'C') {
            fc[ci++] = make_pair(y, x);
        } else {
            fd[di++] = make_pair(y, x);
        }
    }

    sort(fc, fc + ci);
    sort(fd, fd + di);

    if (ci > 0) {
        mxc[0] = fc[0].second;
        for (int i = 1; i < ci; ++i)
            mxc[i] = max(mxc[i - 1], fc[i].second);
    }
    if (di > 0) {
        mxd[0] = fd[0].second;
        for (int i = 1; i < di; ++i)
            mxd[i] = max(mxd[i - 1], fd[i].second);
    }

    int best_c = find_best_c(c);
    int best_d = find_best_d(d);

    for (int i = 0; i < ci && fc[i].first <= c; ++i) {
        int nxt = min(i - 1, find_best_c(c - fc[i].first));
        if (nxt >= 0)
            ans = max(ans, fc[i].second + mxc[nxt]);
        ans = max(ans, fc[i].second + (best_d >= 0 ? mxd[best_d] : (int)-1e9));
    }

    for (int i = 0; i < di && fd[i].first <= d; ++i) {
        int nxt = min(i - 1, find_best_d(d - fd[i].first));
        if (nxt >= 0)
            ans = max(ans, fd[i].second + mxd[nxt]);
        ans = max(ans, fd[i].second + (best_c >= 0 ? mxc[best_c] : (int)-1e9));
    }

    cout << ans << endl;

    return 0;
}