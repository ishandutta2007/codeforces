#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1e6;

struct ST_table{
    vector<vector<int> > d;
    void init(vector<int> a) {
        d = vector<vector<int> >(a.size(), vector<int>(32 - __builtin_clz(a.size()),0));
        for (int i = 0; i < a.size(); i ++)
            d[i][0] = a[i];
        for (int i = 0; i + 1 < d[0].size(); i ++)
            for (int j = 0; j + (1 << (i + 1)) <= a.size(); j ++)
                d[j][i + 1] = min(d[j][i], d[j + (1 <<i)][i]);
    }
    int get(int l, int r) {
        int tmp = 32 - __builtin_clz(r - l + 1) - 1;
        return min(d[l][tmp], d[r - (1 << tmp) + 1][tmp]);
    }
};

int t1[N], t2[N], c[N]; //SA
struct sa{
    vector<int> rank, height, sa;
    ST_table sa_height_table;
    int n;
    bool cmp(int *r,int a,int b,int l)
    {
        return r[a] == r[b] && r[a+l] == r[b+l];
    }

    void init(const vector<char> s, int m)//str[n]01a1n+1sa[0]=n
    {
        n = s.size();
        sa.resize(n);
        int i, j, p;
        int *x = t1;  //Rank[]
        int *y = t2; //
        //s
        for(i = 0; i < m; i++)     c[i] = 0;//c[]
        for(i = 0; i < n; i++)     c[x[i] = s[i]]++;
        for(i = 1; i < m; i++)     c[i] += c[i-1];
        for(i = n-1; i >= 0; i--)  sa[ --c[ x[i] ] ] = i;

        for(j = 1; j <= n; j <<= 1)
        {
            p = 0;         //sa
            for(i = n-j; i < n; i++) y[p++] = i;//j
            for(i = 0; i < n; i++)
                if(sa[i] >= j) y[p++] = sa[i] - j;
            //
            for(i = 0; i < m; i++)     c[i] = 0;
            for(i = 0; i < n; i++)     c[ x[ y[i]]  ]++;
            for(i = 1; i < m; i++)     c[i] += c[i-1];
            for(i = n-1; i >= 0; i--)  sa[ --c[ x[ y[i] ] ] ] = y[i];        //saxx
            /**
             sa  rank 
             rank 
             y  y  rank
            **/
            swap(x, y);  p=1;  x[sa[0]]=0;
            for(i = 1; i < n; i++)
                x[sa[i]] = cmp(y,sa[i-1],sa[i],j) ? p-1 : p++;
            if(p >= n) break;
            m = p;//
        }
        int k = 0;
        height.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++) rank[sa[i]] = i;
        for(int i = 0; i < n - 1; i++)
        {
            if(k) k--;
            int j = sa[rank[i]-1];
            while(max(i + k, j + k) < n  && s[i+k] == s[j+k]) k++;
            height[rank[i]] = k;
        }
        sa_height_table.init(height);

    }
    int lcp(int l, int r) {//0~n - 1
        if (l == r) return n - l - 1;
        if (rank[l] > rank[r]) swap(l, r);
        return sa_height_table.get(rank[l] + 1, rank[r]);
    }
    bool the_same(int s1, int s2, int len) {
        return lcp(s1, s2) >= len;
    }
    int smallest_border(int l, int r) {
        int i;
        for (i = 1; 1ll * i * i <= n && i * 2 <= (r - l + 1); i ++)
            if (the_same(l, r - i + 1, i)) return i;
        if (i * 2 > r - l + 1) return -1;
        int v = -1;
        for (int j = max(rank[l] - i, 0); j <= rank[l] + i && j < n; j ++) {
            if (sa[j] > l && sa[j] <= r && lcp(l, sa[j]) >= r - sa[j] + 1)
                v = max(v, sa[j]);
        }
        if (v < 0) return -1;
        return r - v + 1;
    }
}suffix_sa, prefix_sa;
char s[N];
vector<vector<int> > f;
vector<int> get(int l, int r) {
    if (!l) return f[r];
    vector<int> out(26, 0);
    for (int i = 0; i < 26; i ++)
        out[i] = f[r][i] - f[l - 1][i];
    return out;
}
bool all_0_1_s(const vector<int>&a) {
    for (auto u:a)
        if (u > 1) return 0;
    return 1;
}
int n;
int pre_f[N * 4], suf_f[N * 4], pre_AA[N], suf_AA[N], g[N];
void add(int l, int r, int s, int ll, int rr, int v, int*f) {
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        f[s] = min(f[s], v);
        return;
    }
    add(l, (l + r) / 2, s + s, ll, rr, v, f);
    add((l + r) / 2 + 1, r, s + s + 1, ll, rr, v, f);
}
void update(int l, int r, int s, int pre, int suf) {
    pre = min(pre, pre_f[s]);
    suf = min(suf, suf_f[s]);
    if (l == r) {
        pre_AA[l] = pre;
        suf_AA[l] = suf;
        return;
    }
    update(l, (l + r) / 2, s + s, pre, suf);
    update((l + r) / 2 + 1, r, s + s + 1, pre, suf);
}
int main() {
    scanf("%d", &n);
    scanf("%s", s);
    f = vector<vector<int> > (n, vector<int>(26, 0));
    for (int i = 0; i < n; i ++) {
        s[i] -= ('a' - 1);
        if (i)
            f[i] = f[i - 1];
        f[i][s[i] - 1] ++;
    }
    for (int i = 1; i <= n * 4; i  ++)
        pre_f[i] = suf_f[i] = 1e9;
    s[n] = 0;
    suffix_sa.init(vector<char>(s, s + n + 1), 27);
    reverse(s, s + n);
    prefix_sa.init(vector<char>(s, s + n + 1), 27);
    reverse(s, s + n);
    for (int i = 1; i <= n / 2; i ++) {
        for (int j = 0; j + i < n; j += i) {
            int l = j, r = j + i;
            int x = suffix_sa.lcp(l, r), y = prefix_sa.lcp(n - l - 1, n - r - 1);
            if ((x + y  - 1) < i) continue;
            int len = min(min(x, y), min(x + y - i, i));
            add(0, n - 1, 1, max(l - y + 1, l - i + 1), max(l - y + 1, l - i + 1) + len - 1, i, suf_f);
            add(0, n - 1, 1, min(r + x, r + i) - len, min(r + x, r + i) - 1, i, pre_f);
        }
    }
    update(0, n - 1, 1, 1e9, 1e9);
    int m;
    g[n] = 1e9;
    for (int i = n - 1; i >= 0; i--)
        g[i] = min(g[i + 1], i + suf_AA[i] * 2 - 1);
    scanf("%d", &m);
    int id = 0;
    while (m --) {
        int l, r;
        scanf("%d %d", &l, &r);

        if (++id == 277) {
            int yy;
            yy = 0;
        }
        l --, r --;
        auto u = get(l, r);
        if (all_0_1_s(u)) {
            puts("-1");
            continue;
        }
        bool sig = 0;
        for (int i = 1; 1ll * i * i <= r - l + 1;i ++)
            if ((r - l + 1) % i == 0) {
                int len = (r - l + 1) / i;
                if (i > 1&&suffix_sa.lcp(l, l + len) >= r - l + 1 - len) {
                    sig = 1;
                    break;
                }
                len = i;
                if (suffix_sa.lcp(l, l + len) >= r - l + 1 - len) {
                    sig = 1;
                    break;
                }
            }
        if (sig) {
            puts("1");
            continue;
        }
        if (suffix_sa.smallest_border(l, r) != -1 || suf_AA[l] * 2 <= (r - l + 1) || pre_AA[r] * 2 <= (r - l + 1)) {
            puts("2");
            continue;
        }
        if (u[s[l] - 1] > 1 || u[s[r] - 1] > 1 || g[l] <= r) {
            puts("3");
            continue;
        }
        puts("4");
    }
    return 0;
}