#include<bits/stdc++.h>
#define MN 100000
#define MP 4950
#define N 320
using namespace std;
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='1') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int n, m, q, C, a[MN + 5];
int prime[MN + 5], cnt, ans[1 << 13][1000], ans2[1 << 13][2300], last[MN + 5], num[MN + 5], skip[MP + 5];
short ans3[1 << 13][MP + 5];
int small_sum[MN + 5][14];
bool b[MN + 5];
int v1[MN + 5], v2[MN + 5];
int pair_num;
int pa[MN + 5], pb[MN + 5];
int Div_num = 0;
int Div[MN + 5], pDiv[MN + 5];
int final_ans[MN + 5];
struct ques {
    int id, l, r, L;
    bool operator < (const ques &b) const {
        return L == b.L ? r < b.r : L < b.L;
    }
} s[MN + 5];

inline void inc(int i) {
    num[v1[i]] ++;
    num[v2[i]] ++;
}

inline void del(int i) {
    num[v1[i]] --;
    num[v2[i]] --;
}

int main() {
    n = read(); m = read(); C = read(); q = read();
    for (int i = 2; i <= MN; ++i) {
        if (!b[i]) {
            prime[++cnt] = i;
            last[i] = cnt;
        }
        for (int j = 1; j <= cnt && prime[j] * i <= MN; ++j) {
            b[prime[j] * i] = 1;
            last[prime[j] * i] = j;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    int ccnt = cnt;
    while(ccnt && prime[ccnt] > C || prime[ccnt] > m) --ccnt;
    for (int i = 1; i <= C; ++i) {
        int x = C / i;
        if (!Div_num || (Div_num && Div[Div_num] != x)) {
            Div[++ Div_num] = x;
            pDiv[x] = Div_num;
        }
    }
    for (int i = 14; i <= ccnt; ++i) {
        int pp = pair_num;
        for (int j = i + 1; j <= ccnt && prime[i] * prime[j] <= C; ++j) {
            pa[++pair_num] = i;
            pb[pair_num] = j;
        }
        for (int j = pp; ++j <= pair_num; ++j) {
            skip[j] = pair_num;
        }
    }
    for (int i = 1; i < (1 << 13); ++i) {
        int lowbit = 0;
        while((i & (1 << lowbit)) == 0) ++ lowbit;
        for (int j = 1; j <= Div_num; ++j) {
            ans[i][j] = -(Div[j] / prime[lowbit + 1]) + ans[i ^ (1 << lowbit)][j] - ans[i ^ (1 << lowbit)][pDiv[Div[j] / prime[lowbit + 1]]];
        }
    }
    for (int j = 0; j < (1 << 13); ++j) {
        for (int i = 14; i <= ccnt; ++i) {
            ans2[j][i] = -(C / prime[i]) - ans[j][pDiv[C / prime[i]]];
        }
    }
    for (int j = 0; j < (1 << 13); ++j) {
        for (int i = 1; i <= pair_num; ++i) {
            int x = prime[pa[i]], y = prime[pb[i]];
            ans3[j][i] = (C / x / y) + ans[j][pDiv[C / x / y]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        for (int j = 1; j <= 13; ++j) {
            small_sum[i][j] = small_sum[i - 1][j];
        }
        int vv = 0;
        for (int t = a[i]; t > 1; ) {
            if (last[t] > 13) {
                if (vv) v2[i] = last[t];
                else v1[i] = last[t], ++vv;
            } else {
                ++small_sum[i][last[t]];
            }
            int x = prime[last[t]];
            while(t % x == 0) t /= x;
        }
    }
    for (int i = 1; i <= q; ++i) {
        s[i].id = i;
        s[i].l = read(); s[i].r = read();
        s[i].L = s[i].l / N;
    }
    sort(s + 1, s + q + 1);
    int l = 1, r = 0;
    for (int i = 1; i <= q; ++i) {
        while (l > s[i].l) inc(--l);
        while (r < s[i].r) inc(++r);
        while (l < s[i].l) del(l++);
        while (r > s[i].r) del(r--);
        int mask = 0;
        for (int j = 1; j <= 13; ++j) {
            if (small_sum[s[i].r][j] - small_sum[s[i].l - 1][j]) {
                mask |= (1 << (j - 1));
            }
        }
        int cur_ans = C + ans[mask][1];
        for (int j = 14; j <= ccnt; ++j) {
            if (num[j]) {
                cur_ans += ans2[mask][j];
            }
        }
        for (int j = 1; j <= pair_num; ++j) {
            if (num[pa[j]]) {
                if (num[pb[j]]) {
                    cur_ans += ans3[mask][j];
                }
            } else {
                j = skip[j];
            }
        }
        final_ans[s[i].id] = cur_ans;
    }
    for (int i = 1; i <= q; ++i) {
        printf("%d\n", final_ans[i]);
    }
    return 0;
}