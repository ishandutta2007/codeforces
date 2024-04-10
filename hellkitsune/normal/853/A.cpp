#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int c[300000];

priority_queue<PII> q;

int t[300000];

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d", c + i);
    forn(i, k + 1) if (i < n) {
        q.push(mp(c[i], i + 1));
    }
    int nx = k + 1;
    LL cost = 0;
    for (int i = k + 1; i <= n + k; ++i) {
        int ind = q.top().second;
        int w = q.top().first;
        q.pop();
        cost += (i - ind) * (LL)w;
        t[ind - 1] = i;
        if (nx < n) {
            q.push(mp(c[nx], nx + 1));
            ++nx;
        }
    }
    cout << cost << endl;
    forn(i, n) printf("%d ", t[i]);
    puts("");
    return 0;
}