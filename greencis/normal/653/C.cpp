#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n, a[200105], trouble[200105];
ll ans;

int find_trouble(int l, int r) {
    if (l > r || trouble[r] - trouble[l - 1] == 0) return -1;
    if (trouble[l] - trouble[l - 1] > 0) return l;
    int L = l, R = r;
    while (L < R) {
        int mid = (L + R + 1) / 2;
        int val = trouble[mid] - trouble[l - 1];
        if (val > 0) R = mid - 1;
        else L = mid;
    }
    if (L == r) return -1;
    return L + 1;
}

inline bool correct(int idx) {
    if (idx < 1 || idx > n) return true;
    if (idx % 2 == 0)
        return a[idx - 1] < a[idx] && a[idx + 1] < a[idx];
    return a[idx - 1] > a[idx] && a[idx + 1] > a[idx];
}

bool check() {
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            if (a[i-1] <= a[i] || a[i] >= a[i+1]) return false;
        } else {
            if (a[i-1] >= a[i] || a[i] <= a[i+1]) return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    a[0] = 1e9;
    if (n % 2 == 0) a[n + 1] = -1e9;
    else a[n + 1] = 1e9;

    for (int i = 1; i <= n; ++i)
        trouble[i] = trouble[i - 1] + !correct(i);

    vector<pii> v;
    vector<int> vv;
    int curidx = 1;
    while (curidx <= n) {
        int idx = find_trouble(curidx, n);
        if (idx == -1) break;
        int newidx = idx;
        while (newidx <= n && trouble[newidx] - trouble[newidx - 1] > 0) ++newidx;
        v.push_back(make_pair(idx, newidx - 1));
        curidx = newidx;
    }

    if (v.size() >= 3) { cout << "0"; return 0; }
    else if (v.size() == 2) {
        if (v[0].second - v[0].first + 1 >= 7 || v[1].second - v[1].first + 1 >= 7) { cout << "0"; return 0; }
        for (int i = v[0].first; i <= v[0].second; ++i)
            vv.push_back(i);
        for (int i = v[1].first; i <= v[1].second; ++i)
            vv.push_back(i);

        for (int i = 0; i < vv.size(); ++i) {
            for (int j = i + 1; j < vv.size(); ++j) {
                swap(a[vv[i]], a[vv[j]]);
                ans += check();
                swap(a[vv[i]], a[vv[j]]);
            }
        }
    }
    else if (v.size() == 1) {
        if (v[0].second - v[0].first + 1 >= 7) { cout << "0"; return 0; }
        int L = v[0].first, R = v[0].second;
        for (int i = L; i <= R; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j)  continue;
                if (L <= j && j <= R && j > i) continue;
                swap(a[i], a[j]);
                int good = 1;
                good &= correct(j - 1) && correct(j) && correct(j + 1);
                for (int z = max(1, L - 1); z <= min(n, R + 1); ++z)
                    good &= correct(z);
                ans += good;
                swap(a[i], a[j]);
            }
        }
    }
    else throw;


    cout << ans;

    return 0;
}