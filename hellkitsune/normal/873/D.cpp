#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[100000];
int b[100000];

void solve(int from, int to) {
    if (k >= 2 && to >= from + 2) {
        int mid = (from + to) >> 1;
        forn(i, to - from) {
            b[i] = a[from + i];
        }
        int pos = 0;
        for (int i = mid; i < to; ++i) {
            a[i] = b[pos++];
        }
        for (int i = from; i < mid; ++i) {
            a[i] = b[pos++];
        }
        k -= 2;
        solve(from, mid);
        solve(mid, to);
    }
}

int main() {
    cin >> n >> k;
    forn(i, n) a[i] = i + 1;
    --k;
    solve(0, n);
    if (k != 0) {
        cout << -1 << endl;
        return 0;
    }
    forn(i, n) printf("%d ", a[i]);
    puts("");
    return 0;
}