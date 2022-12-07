#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair<int, int> PII;

int c, n;
int cnt[200005] = {};
int le[200005];

int main() {
    scanf("%d%d", &c, &n);
    forn(i, n) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }
    le[0] = -1;
    for (int i = 1; i <= 200001; ++i) {
        if (cnt[i] > 0) {
            le[i] = i;
        } else {
            le[i] = le[i - 1];
        }
    }
    int ans = 200001;
    for (int i = c; i > 0; ) {
        int rem = c - i;
        int pos = min(rem, i);
        while (rem) {
            pos = min(pos, rem);
            pos = le[pos];
            if (pos == -1) {
                break;
            }
            int can = min(cnt[pos], rem / pos);
            rem -= can * pos;
            --pos;
        }
        if (rem != 0) {
            ans = i;
        }

        int can = min(c / i, cnt[i]);
        c -= can * i;
        i = min(i - 1, c);
    }
    if (ans == 200001) {
        cout << "Greed is good" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}