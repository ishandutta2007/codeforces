#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
int a[100][100];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    forn(i, n) forn(j, m) {
        scanf("%d", a[j] + i);
    }
    swap(n, m);
    int score = 0;
    int mn = 0;
    forn(i, n) {
        int best = 0;
        int cur = 0;
        int bestScore = 0;
        forn(j, m) if (a[i][j] == 1) {
            int curScore = 0;
            forn(p, k) if (j + p < m) {
                curScore += a[i][j + p];
            }
            if (curScore > bestScore) {
                bestScore = curScore;
                best = cur;
            }
            ++cur;
        }
        mn += best;
        score += bestScore;
    }
    cout << score << ' ' << mn << endl;
    return 0;
}