#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[10005];
int nx[1000005][26] = {};
int fin[1000005];
int cnt = 1;
string a[100000];
char buf[1005];
int d[10005];
vector<string> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%d", &m);
    REP(i, m) {
        scanf("%s", buf);
        a[i] = string(buf);
    }
    memset(fin, -1, sizeof fin);
    REP(i, m) {
        int pos = 0;
        reverse(a[i].begin(), a[i].end());
        for (char c : a[i]) {
            int x;
            if (c >= 'a' && c <= 'z') x = c - 'a';
            else x = c - 'A';
            if (!nx[pos][x]) {
                nx[pos][x] = cnt++;
            }
            pos = nx[pos][x];
        }
        fin[pos] = i;
        reverse(a[i].begin(), a[i].end());
    }
    memset(d, -1, sizeof d);
    d[0] = 0;
    REP(i, n) if (d[i] != -1) {
        int pos = 0;
        for (int j = i; j < n; ++j) {
            pos = nx[pos][s[j] - 'a'];
            if (pos == 0) break;
            if (fin[pos] != -1) {
                d[j + 1] = fin[pos];
            }
        }
    }
    for (int i = n; i > 0; i -= (int)a[d[i]].size()) {
        ans.pb(a[d[i]]);
    }
    for (int i = (int)ans.size() - 1; i >= 0; --i) {
        printf("%s", ans[i].c_str());
        if (i != 0) printf(" ");
    }
    printf("\n");
    return 0;
}