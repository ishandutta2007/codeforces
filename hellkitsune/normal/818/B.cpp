#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int l[100], a[100];
bool used[101] = {};

int main() {
    scanf("%d%d", &n, &m);
    forn(i, m) scanf("%d", l + i), --l[i];
    memset(a, -1, sizeof a);
    forn(i, m - 1) {
        int dist = (l[i + 1] - l[i] + n) % n;
        if (dist == 0) dist = n;
        if ((a[l[i]] == -1 && used[dist]) || (a[l[i]] != -1 && a[l[i]] != dist)) {
            cout << -1 << endl;
            return 0;
        }
        used[dist] = true;
        a[l[i]] = dist;
    }
    int ind = 1;
    forn(i, n) if (a[i] == -1) {
        while (used[ind]) ++ind;
        assert(ind <= n);
        a[i] = ind++;
    }
    forn(i, n) cout << a[i] << ' ';
    cout << endl;
    return 0;
}