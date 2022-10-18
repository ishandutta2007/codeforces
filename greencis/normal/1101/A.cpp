#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) {
        int l, r, d;
        cin >> l >> r >> d;
        int la = (l + d - 1) / d;
        int ra = r / d;
        if (la == 1)
            ++ra;
        else
            ra = 1;
        cout << ra * d << endl;
    }
}