#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> a[2];

void readVec(vector<int> &v) {
    int cnt;
    scanf("%d", &cnt);
    forn(i, cnt) {
        int x;
        scanf("%d", &x);
        v.pb(n - x);
    }
    sort(v.begin(), v.end());
}

int ans[2][7000] = {};
int cnt[2][7000] = {};

queue<PII> q;

int main() {
    scanf("%d", &n);
    readVec(a[0]);
    readVec(a[1]);
    ans[0][0] = -1;
    ans[1][0] = -1;
    q.push(mp(0, 0));
    q.push(mp(1, 0));
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        int oth = i ^ 1;
        if (ans[i][j] == -1) {
            for (int x : a[oth]) {
                int nj = j + x;
                if (nj >= n) {
                    nj -= n;
                }
                if (ans[oth][nj] == 0) {
                    ans[oth][nj] = 1;
                    q.push(mp(oth, nj));
                }
            }
        } else {
            for (int x : a[oth]) {
                int nj = j + x;
                if (nj >= n) {
                    nj -= n;
                }
                if (++cnt[oth][nj] == (int)a[oth].size()) {
                    if (ans[oth][nj] == 0) {
                        ans[oth][nj] = -1;
                        q.push(mp(oth, nj));
                    }
                }
            }
        }
    }
    forn(i, 2) {
        forn(j, n) if (j) {
            if (ans[i][j] == -1) {
                printf("Lose ");
            } else if (ans[i][j] == 1) {
                printf("Win ");
            } else {
                printf("Loop ");
            }
        }
        puts("");
    }
    return 0;
}