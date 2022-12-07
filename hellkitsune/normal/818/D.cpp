#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a;
int cnt[1000001];
bool bad[1000001] = {};

int main() {
    scanf("%d%d", &n, &a);
    int ac = 0;
    bad[a] = true;
    forn(i, n) {
        int col;
        scanf("%d", &col);
        if (col == a) {
            ++ac;
        } else {
            if (cnt[col] < ac) {
                bad[col] = true;
            }
            ++cnt[col];
        }
    }
    for (int i = 1; i <= 1000000; ++i) {
        if (!bad[i] && cnt[i] >= ac) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}