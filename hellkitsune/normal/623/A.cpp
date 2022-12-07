#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
bool e[500][500];
int col[500];
char ans[505];

vector<int> tmp;
void dfs(int v) {
    tmp.pb(v);
    REP(i, n) if (e[v][i]) {
        if (col[i] == -1) {
            col[i] = col[v] ^ 1;
            dfs(i);
        } else if (col[i] == col[v]) {
            printf("No\n");
            exit(0);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) REP(j, n) e[i][j] = true;
    REP(i, n) e[i][i] = false;
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        e[from][to] = e[to][from] = false;
    }
    REP(i, n) col[i] = -1;
    int cnt = 0;
    REP(i, n) ans[i] = 'b';
    ans[n] = '\0';
    REP(i, n) if (col[i] == -1) {
        col[i] = 0;
        tmp.clear();
        dfs(i);
        if ((int)tmp.size() > 1) {
            ++cnt;
            for (int x : tmp) for (int y : tmp) if (col[x] != col[y] && e[x][y] == false) {
                printf("No\n");
                return 0;
            }
            for (int x : tmp) if (col[x] == 0) {
                ans[x] = 'a';
            } else {
                ans[x] = 'c';
            }
        }
    }
    if (cnt > 1) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    printf("%s\n", ans);
    return 0;
}