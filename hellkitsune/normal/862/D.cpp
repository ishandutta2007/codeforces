#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;

int ask(string s) {
    cout << "? " << s << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    string zeros(n, '0');
    string ones(n, '1');

    int base = ask(ones);
    string cur = ones;
    cur[0] = '0';
    if (ask(cur) < base) {
        base = ask(zeros);
        int lo = 1, hi = n - 1, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            cur = zeros;
            forn(i, mid + 1) {
                cur[i] = '1';
            }
            if (ask(cur) == base + mid + 1) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        cout << "! " << 1 << ' ' << lo + 1 << endl;
    } else {
        int lo = 1, hi = n - 1, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            cur = ones;
            forn(i, mid + 1) {
                cur[i] = '0';
            }
            if (ask(cur) == base + mid + 1) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        cout << "! " << lo + 1 << ' ' << 1 << endl;
    }
    return 0;
}