#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[200105];
void ans(int idx) {
    if (idx >= 1) {
        cout << "2 " << idx << "\n";
        for (int i = 1; i + 1 < idx; ++i)
            cout << "1 " << i << " " << i + 1 << "\n";
        if (idx - 1 >= 1 && idx + 1 <= n)
            cout << "1 " << idx - 1 << " " << idx + 1 << "\n";
        for (int i = idx + 1; i + 1 <= n; ++i)
            cout << "1 " << i << " " << i + 1 << "\n";
    } else {
        for (int i = 1; i + 1 <= n; ++i)
            cout << "1 " << i << " " << i + 1 << "\n";
    }
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);

    int x, pos = 0, neg = 0, zeroidx = 0;
    pii mxneg = {-2e9, -1};
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a[i] = x;
        if (x > 0)
            ++pos;
        else if (x < 0) {
            ++neg;
            mxneg = max(mxneg, {x, i});
        } else
            zeroidx = i;
    }
    if (zeroidx) {
        if (pos == 0 && neg <= 1)
            ans(0);
        vector<int> va, vb;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0 || i == mxneg.second && neg % 2 != 0)
                va.push_back(i);
            else
                vb.push_back(i);
        }
        for (int i = 1; i < (int)va.size(); ++i)
            cout << "1 " << va[i] << " " << va[0] << "\n";
        cout << "2 " << va[0] << "\n";
        for (int i = 1; i < (int)vb.size(); ++i)
            cout << "1 " << vb[i] << " " << vb[0] << "\n";
        exit(0);
    }
    if (neg % 2 == 0)
        ans(0);
    ans(mxneg.second);
}