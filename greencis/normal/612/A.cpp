#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,p,q;
string s;

int main()
{
    cin >> n >> p >> q >> s;
    for (int i = 0; i * p <= n; ++i) {
        if ((n - i * p) % q) continue;
        int cnt1 = i, cnt2 = (n - i * p) / q;
        cout << cnt1 + cnt2 << endl;
        int idx = 0;
        while (cnt1--) {
            cout << s.substr(idx, p) << endl;
            idx += p;
        }
        while (cnt2--) {
            cout << s.substr(idx, q) << endl;
            idx += q;
        }
        return 0;
    }
    cout << -1;

    return 0;
}