#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll n;
int q;
ll L[99], R[99];
int sti;
ll x;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    while (q--) {
        string s;
        cin >> x >> s;
        sti = 1;
        L[0] = 1;
        R[0] = n;
        while (L[sti - 1] + R[sti - 1] != 2 * x) {
            ll mid = (L[sti - 1] + R[sti - 1]) / 2;
            if (x < mid)
                L[sti] = L[sti - 1], R[sti] = mid - 1;
            else
                L[sti] = mid + 1, R[sti] = R[sti - 1];
            ++sti;
        }
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == 'U') {
                if (sti == 1)
                    continue;
                --sti;
            } else if (s[i] == 'L') {
                if (L[sti - 1] == R[sti - 1])
                    continue;
                ll mid = (L[sti - 1] + R[sti - 1]) / 2;
                L[sti] = L[sti - 1], R[sti] = mid - 1;
                ++sti;
            } else {
                if (L[sti - 1] == R[sti - 1])
                    continue;
                ll mid = (L[sti - 1] + R[sti - 1]) / 2;
                L[sti] = mid + 1, R[sti] = R[sti - 1];
                ++sti;
            }
        }

        cout << (L[sti - 1] + R[sti - 1]) / 2 << "\n";
    }

    return 0;
}