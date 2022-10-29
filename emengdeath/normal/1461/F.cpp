#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
const int MX = 1e6;
int n;
int a[N];
char b[N];
char s[10];
map<char, bool> f;
vector<pair<int, pair<int, int> > > A, B;
bool bz[N], bz1[N];
int ans;
int calc() {
    int v = 0;
    int now = A[0].first;
    for (int i = 0; i < B.size(); i ++)
        if (bz[i]) {
            now *= A[i + 1].first;
        } else {
            v += now + B[i].first;
            now = A[i + 1].first;
        }
    v += now;
    return v;
}
void dfs(int x) {
    if (x == B.size()) {
        int v = calc();
        if (v > ans) {
            ans = v;
            for (int i = 0; i < B.size(); i ++)
                bz1[i] = bz[i];
        }
        return;
    }
    for (int i = 0; i < 2; i ++) bz[x] = i, dfs(x + 1);
}
void work(int l, int r) {
    int v = 1;
    int sum = 0;
    int mn = 9;
    for (int i = l; i <= r; i ++) {
        v = min(v * a[i], MX);
        sum += (a[i] == 1);
        if (a[i] != 1) mn = min(a[i], mn);
    }
    if (v == MX || (mn && (v > v / mn + mn + sum)) ) return;
    int ll = l;
    A.clear();
    B.clear();
    while (ll <= r) {
        if (a[ll] == 1) {
            int cnt = 0;
            int L = ll;
            while (a[ll] == 1 && ll <= r) {
                ll ++;
                ++cnt;
            }
            B.push_back({cnt, {L, ll - 1}});
        } else {
            int v = 1;
            int L = ll;
            while (a[ll] != 1 && ll <= r) {
                v *= a[ll];
                ++ll;
            }
            A.push_back({v, {L, ll - 1}});
        }
    }
    ans = -1;
    dfs(0);
    for (int i = 0; i < B.size(); i ++)
        if (!bz1[i])
            for (int j = B[i].second.first; j <= B[i].second.second; j ++)
                b[j] = b[j - 1] = '+';
}
void work() {
    for (int i = 1; i <= n;i ++)
        if (!a[i])
            b[i - 1] = b[i] = '+';
    int l = 1;
    while (l <= n) {
        while (l <= n && !a[l]) ++l;
        int r = l;
        while (r + 1 <= n && a[r + 1]) ++r;
        int rr = r;
        while (l <= r && a[l] == 1) {
            b[l] = '+';
            b[l - 1] = '+';
            ++l;
        }
        while (l <= r && a[r] == 1) {
            b[r - 1] = '+';
            b[r] = '+';
            r --;
        }
        for (int i = l; i < r; i ++) b[i] = '*';
        if (l <= r) {
            work(l, r);
        }
        l = rr + 1;
    }
    for (int i = 1; i <= n; i ++)
    {
        printf("%d", a[i]);
        if (i != n)
            printf("%c", b[i]);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i ++)
        f[s[i]] = 1;
    if (!f['*']) {
        if (!f['+']) {
            for (int i = 1; i <= n;i ++) {
                printf("%d", a[i]);
                if (i != n) printf("-");
            }
            return 0;
        } else {
            for (int i = 1; i <= n;i ++) {
                printf("%d", a[i]);
                if (i != n) printf("+");
            }
            return 0;
        }
    } else {
        if (!f['+']) {
            if (!f['-']) {
                for (int i = 1; i <= n;i ++) {
                    printf("%d", a[i]);
                    if (i != n) printf("*");
                }
                return 0;
            } else {
                for (int i = 1; i <= n;i ++) {
                    printf("%d", a[i]);
                    if (i != n) {
                        if (a[i + 1] == 0)
                            printf("-");
                        else printf("*");
                    }
                }
                return 0;
            }
        } else {
            work();
        }
    }
    return 0;
}