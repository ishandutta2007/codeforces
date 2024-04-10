#include <bits/stdc++.h>
#ifndef LOCAL
#define cerr if(0)cerr
#endif // LOCAL
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int an = -1, am = -1;
        int x;
        cin >> x;
        if (x == 0) {
            cout << "1 1\n";
            continue;
        }
        for (int i = 1; an == -1 && i * i < x; ++i) {
            if (x % i != 0) continue;
            int xi = x / i;
            if ((i + xi) % 2 == 1) continue;
            int n = (xi + i) / 2;
            int z = (xi - i) / 2;
            int L = 1, R = n;
            while (L < R) {
                int mid = (L + R + 1) >> 1;
                int qqq = n / mid;
                if (qqq >= z)
                    L = mid;
                else
                    R = mid - 1;
            }
            if (n / L == z) {
                an = n;
                am = L;
            }
        }
        if (an == -1) cout << "-1\n";
        else cout << an << " " << am << "\n";
    }

    return 0;
}