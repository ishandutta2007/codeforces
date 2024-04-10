#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    ios_base::sync_with_stdio(false);

   /* for (int i = 1; i <= (1 << 25) - 1; i = i * 2 + 1) {
        int mx = -1, mxi = -1;
        for (int b = 1; b < i; ++b) {
            int cur = gcd(i ^ b, i & b);
            if (cur > mx)
                mx = cur, mxi = b;
        }
        cout << "if (x == " << i << ") cout << " << mx << " << \"\\n\";\n";
    }*/

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x & (x + 1)) {
            int cur = 0;
            while (x)
                ++cur, x /= 2;
            cout << ((1 << cur) - 1) << "\n";
        } else { // 7 15 31
            if (x == 3) cout << 1 << "\n";
            if (x == 7) cout << 1 << "\n";
            if (x == 15) cout << 5 << "\n";
            if (x == 31) cout << 1 << "\n";
            if (x == 63) cout << 21 << "\n";
            if (x == 127) cout << 1 << "\n";
            if (x == 255) cout << 85 << "\n";
            if (x == 511) cout << 73 << "\n";
            if (x == 1023) cout << 341 << "\n";
            if (x == 2047) cout << 89 << "\n";
            if (x == 4095) cout << 1365 << "\n";
            if (x == 8191) cout << 1 << "\n";
            if (x == 16383) cout << 5461 << "\n";
            if (x == 32767) cout << 4681 << "\n";
            if (x == 65535) cout << 21845 << "\n";
            if (x == 131071) cout << 1 << "\n";
            if (x == 262143) cout << 87381 << "\n";
            if (x == 524287) cout << 1 << "\n";
            if (x == 1048575) cout << 349525 << "\n";
            if (x == 2097151) cout << 299593 << "\n";
            if (x == 4194303) cout << 1398101 << "\n";
            if (x == 8388607) cout << 178481 << "\n";
            if (x == 16777215) cout << 5592405 << "\n";
            if (x == 33554431) cout << 1082401 << "\n";
        }
    }
}