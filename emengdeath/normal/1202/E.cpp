#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1e6 + 2;
struct node{
    int son[26];
    int sum1, sum2, fail;
    int len;
    vector<int>g;
}f[N];
char t[N], s[N];
long long ans;
int n, tot;
int d[N], e[N], du[N];
int main() {
    scanf("%s", &t);
    scanf("%d", &n);
    while (n --){
        scanf("%s", s);
        int x = 0, l = 0;
        int len = strlen(s);
        while (l < len) {
            if (!f[x].son[s[l] - 'a'])
                f[f[x].son[s[l] - 'a'] = ++tot].len = f[x].len + 1;
            x = f[x].son[s[l] - 'a'];
            l ++;
        }
        f[x].sum1 ++;
        reverse(s, s + len);
        x = 0, l = 0;
        while (l < len) {
            if (!f[x].son[s[l] - 'a'])
                f[f[x].son[s[l] - 'a'] = ++tot].len = f[x].len + 1;
            x = f[x].son[s[l] - 'a'];
            l ++;
        }
        f[x].sum2 ++;
    }
    int l = 0, r = 1;
    d[1] = 0;
    while (l != r) {
        ++l;
        for (int i = 0; i < 26; i ++)
            if (f[d[l]].son[i]) {
                d[++r] = f[d[l]].son[i];
                int x = f[d[l]].fail;
                while (x && f[x].son[i] == 0) x = f[x].fail;
                if (f[x].son[i] != d[r]) {
                    f[d[r]].fail = f[x].son[i];
                    f[f[x].son[i]].g.push_back(d[r]);
                    du[d[r]] ++;
                }
            }
    }
    l = r = 0;
    for (int i = 0; i <= tot; i++)
        if (!du[i])
            d[++r] = i;
    while (l!= r) {
        for (auto u:f[d[++l]].g)
            if (!(--du[u])) {
                d[++r] = u;
                f[u].sum1 += f[d[l]].sum1, f[u].sum2 += f[d[l]].sum2;
            }
        d[l] = 0;
    }
    int len = strlen(t);
    int x = 0;
    for (int i = 0; i < len; i ++) {
        while (x && !f[x].son[t[i] - 'a']) x = f[x].fail;
        if (f[x].son[t[i] -'a'])
            x = f[x].son[t[i] - 'a'];
        if (f[x].sum1) {
            d[i] = f[x].sum1;
        }
    }
    x= 0;
    for (int i = len - 1; i >= 0; i --) {
        while (x && !f[x].son[t[i] - 'a']) x = f[x].fail;
        if (f[x].son[t[i] -'a'])
            x = f[x].son[t[i] - 'a'];
        if (f[x].sum2) {
            e[i] = f[x].sum2;
        }
    }
    for (int i = 0; i < len ; i ++)
        ans += 1ll * d[i] * e[i+ 1];
    printf("%lld\n", ans);
    return 0;
}