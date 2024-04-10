#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e6;
const long long mod = 1e18;
const int MASK = (1 << 30) - 1;
int n, w;
long long ans[2];
long long ans1;
char s[N];
int Next[N], Next_c[N][26];//ij+1
struct node{
    bool tag;
    int tagv;
    int sum, v;
    long long allv;
}f[N * 4];
int bz[N];
int tag;
vector<pair<int, int> > d;
void down(int l, int r, int s) {
    if (f[s].tag) {
        f[s].allv = 1ll * f[s].sum * f[s].tagv;
        f[s].v = f[s].tagv;
        if (l != r)
            f[s+s].tag = f[s+s+1].tag = 1, f[s+s].tagv = f[s+s+1].tagv = f[s].tagv;
        f[s].tag = 0;
    }
}
void combine(node&a, node b, node c) {
    a.allv = b.allv + c.allv;
    a.sum = b.sum + c.sum;
}
void ins(int l, int r, int s, int ll, int sum) {
    down(l, r, s);
    if (r < ll || l > ll) return;
    if (l == r) {
        f[s].sum = sum;
        f[s].allv = 1ll * f[s].v * f[s].sum;
        return;
    }
    ins(l, (l + r ) / 2, s + s, ll, sum);
    ins((l + r ) / 2 + 1, r, s + s + 1, ll, sum);
    combine(f[s], f[s+s],f[s+s+1]);
}
void add(int l, int r, int s, int ll, int rr, int v) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr ){
        f[s].tag = 1;
        f[s].tagv = v;
        down(l, r, s);
        return;
    }
    add(l, (l + r) / 2, s + s, ll, rr, v);
    add((l + r) / 2 + 1 , r, s + s + 1, ll, rr, v);
    combine(f[s],f[s+s],f[s+s+1]);
}
void dfs(int x, int c, int wz) {
    if (bz[x] == tag) return;
    bz[x] = tag;
    ins(0, n, 1, wz - x - 1, 0);
    for (int i = 0; i < 26; i ++)
        if (Next_c[x][i] && i != c)
            dfs(Next_c[x][i] - 1, c, wz);
}
void output() {
    if (ans[1]) {
        printf("%lld", ans[1]);
        for (long long i = mod / 10; i >= 1; i/= 10)
            printf("%lld", ans[0]/ i % 10);
    } else {
        printf("%lld\n",ans[0]);
    }
    printf("\n");
}
int main() {
    //freopen("input","r",stdin);
    Next[0] = 0;
    scanf("%d", &n);
    scanf(" %c %d", &s[0],& w);
    s[0] -= 'a';
    ans[0] = w;
    ans1 = w;
    output();
    ins(0, n, 1, 0, 1);
    add(0, n, 1, 0, 0, w);
    d.push_back(make_pair(0, w));
    for (int i=1, j = 0 ;i<n;i++){
        scanf(" %c %d", &s[i], &w);
        w = w ^ (ans1 & MASK);
        s[i] -= 'a';
        s[i] = (s[i] + ans[1] * (mod % 26) % 26 + ans[0]) % 26;
        while (j && s[i] != s[j]) {
            ins(0, n, 1, i - j, 0);
            j = Next[j - 1];
        }
        if (s[i] == s[j]){
            for (int k = 0; k < 26; k ++) {
                Next_c[i][k] = Next_c[j][k];
            }
            Next_c[i][s[j + 1]] = j + 1;
            ++tag;
            if (j)
            for (int k = 0; k < 26; k ++)
                if (Next_c[j - 1][k] && k != s[i])
                    dfs(Next_c[j - 1][k] - 1, s[i], i);
            j ++;
        }
        if (s[0] == s[i]){
            ins(0, n, 1, i, 1);
        }
        Next[i] = j;
        while (d.size() && d[d.size() - 1].second >= w) d.pop_back();
        if (!d.size()) {
            add(0, n, 1, 0, i, w);
        } else {
            add(0, n, 1, d[d.size() - 1].first + 1, i, w);
        }
        d.push_back(make_pair(i,w));
        ans[0] += f[1].allv;
        ans[1] += ans[0] / mod;
        ans[0] %= mod;
        ans1 += f[1].allv;
        output();
    }
    return 0;
}