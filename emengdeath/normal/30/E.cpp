#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int n;
char s[N], t[N];
int len[N];
int Next[N], mn[N];
pair<int, int> f[N * 4];
vector<pair<int, int> > g[N], gg[N];
void insert(int l, int r, int s, int ll, pair<int, int> v) {
    if (l == r) {
        f[s] = v;
        return;
    }
    if ((l + r) / 2 >= ll)
        insert(l, (l + r) / 2, s + s, ll, v);
    else
        insert((l + r) / 2 + 1, r, s + s + 1, ll, v);
    f[s] = max(f[s + s], f[s + s + 1]);
}
pair<int, int> get(int l, int r, int s, int ll, int rr) {
    if (r < ll || rr < l) return {0, 0};
    if (ll <= l && r <= rr) return f[s];
    return max(get(l, (l+ r)/ 2, s + s, ll, rr), get((l + r) /2 + 1, r, s+ s+ 1, ll, rr));
}
int main() {
    scanf("%s",  s);
    n = strlen(s);
    t[0] = '$';
    for (int i = 0; i < n; i ++) {
        t[i * 2 + 1] = '#';
        t[i * 2 + 2] = s[i];
    }
    t[n * 2 + 1] = '#';
    t[n * 2 + 2] = '%';
    int nn = (n + 1) * 2;
    int x = 0;
    for (int i = 1; i < nn; i ++) {
        if (len[x] + x > i) {
            len[i] = min(len[x + x - i], len[x] + x - i);

        }
        while (t[len[i] + i + 1] == t[i - len[i] - 1]) len[i] ++;
        if ('a'<=t[i] && t[i] <= 'z') {
            int ii = i / 2 - 1;
            int slen = len[i] / 2;
            insert(0, n -1 , 1, ii, {len[i], ii});
            gg[ii - slen].push_back({0, ii});
            g[ii + slen].push_back({0, ii});
        }
        if (len[i] + i > x + len[x]) x = i;
    }
    for (int i = 0; i < n; i ++) t[i] = s[n - i - 1];
    Next[0] = 0;
    for (int i = 1, j = 0; i < n; i ++) {
        while (j && t[i] != t[j]) j = Next[j - 1];
        if (t[i] == t[j]) j ++;
        Next[i] = j;
    }
    for (int i = 1; i <= n; i ++)
        mn[i] = n;
    for (int i = 0, j = 0; i < n; i ++) {
        if (j == n) j = Next[j - 1];
        while (j && s[i] != t[j]) j = Next[j - 1];
        if (s[i] == t[j]) {
            j ++;
            mn[j] = min(i,  mn[j]);
        }
    }
    for (int i = n; i >= 1; i --)
        mn[Next[i - 1]] = min(mn[Next[i - 1]], mn[i]);
    int anslen = f[1].first;
    vector<pair<int, int> > ans;
    ans.push_back({f[1].second - f[1].first / 2, f[1].second  +f[1].first / 2});
    mn[0] = -1;
    int l = 0;
    for (int i = 1; i <= (n - 1) / 2; i ++) {
        for (auto u:g[n - i])
            insert(0, n - 1, 1, u.second, u);
        while (mn[i] >= l) {
            for (auto u:gg[l])
                insert(0, n - 1, 1, u.second, u);
            ++ l;
        }
        auto u = get(0, n -1, 1, mn[i] + 1, n - i - 1);
        if (u.first && u.first + i * 2 > anslen) {
            anslen = u.first + i * 2;
            ans.clear();
            ans.push_back({mn[i] - i + 1, mn[i]});
            ans.push_back({u.second - u.first / 2, u.second  +u.first / 2});
            ans.push_back({n - i, n - 1});
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto u:ans)
        printf("%d %d\n", u.first + 1, u.second - u.first + 1);
    return 0;
}