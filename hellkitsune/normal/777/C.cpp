#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> a[100000], to[100000];
int bound[100000];

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        a[i].resize(m);
        to[i].resize(m);
        forn(j, m) {
            scanf("%d", &a[i][j]);
        }
    }
    forn(i, m) {
        to[n - 1][i] = n - 1;
        for (int j = n - 2; j >= 0; --j) {
            if (a[j][i] <= a[j + 1][i]) {
                to[j][i] = to[j + 1][i];
            } else {
                to[j][i] = j;
            }
        }
    }
//    forn(i, n) {
//        forn(j, m) cerr << to[i][j] << ' ';
//        cerr << endl;
//    }
    forn(i, n) {
        bound[i] = i;
        forn(j, m) {
            bound[i] = max(bound[i], to[i][j]);
        }
    }
    int q;
    scanf("%d", &q);
    forn(_, q) {
        int l, r;
        scanf("%d%d", &l, &r), --l, --r;
        if (bound[l] >= r) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}