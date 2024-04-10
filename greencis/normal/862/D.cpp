#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;

int query(string s) {
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    int L = 0, R = n - 1;
    int pos0 = -1, pos1 = -1;
    string s = "";
    for (int i = 0; i < n; ++i)
        s += "0";
    int prv = query(s);
    while (L <= R && (pos0 == -1 || pos1 == -1)) {
        int mid = (L + R) >> 1;
        int pc = s[L] - 48;
        for (int i = L; i <= mid; ++i)
            s[i] ^= 1;
        int cur = query(s);
        if (cur + (mid - L + 1) == prv && pc == 1 || cur - (mid - L + 1) == prv && pc == 0) { /// 1 -> 0
            pos0 = L;
            L = mid + 1;
            prv = cur;
        } else if (cur + (mid - L + 1) == prv && pc == 0 || cur - (mid - L + 1) == prv && pc == 1) { /// 0 -> 1
            pos1 = L;
            L = mid + 1;
            prv = cur;
        } else {
            R = mid;
            prv = cur;
        }
    }
    cout << "! " << (pos0 + 1) << " " << (pos1 + 1) << endl;

    return 0;
}