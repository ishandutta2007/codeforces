#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int sz[1000000] = {}, num[1000][1000];
char s[1000][1005];
int n, m;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
bool used[1000000] = {};

int cm = 0;
void dfs(int i, int j) {
    num[i][j] = cm;
    ++sz[cm];
    REP(dir, 4) {
        int ni = i + dx[dir];
        int nj = j + dy[dir];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m || s[ni][nj] != '.' || num[ni][nj] != -1) continue;
        dfs(ni, nj);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    memset(num, -1, sizeof num);
    REP(i, n) REP(j, m) if (s[i][j] == '.' && num[i][j] == -1) {
        dfs(i, j);
        ++cm;
    }
    REP(i, n) REP(j, m) if (s[i][j] != '.') {
        int ans = 1;
        REP(dir, 4) {
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || s[ni][nj] != '.' || used[num[ni][nj]]) continue;
            used[num[ni][nj]] = true;
            ans += sz[num[ni][nj]];
        }
        REP(dir, 4) {
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || s[ni][nj] != '.') continue;
            used[num[ni][nj]] = false;
        }
        s[i][j] = char('0' + (ans % 10));
    }
    REP(i, n) printf("%s\n", s[i]);
    return 0;
}