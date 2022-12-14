#include<bits/stdc++.h>
#define MN 300000
#define N 524288
#define ll long long
#define INF 1000001
using namespace std;
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='1') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int n, m, q, p[MN + 5], a[MN + 5], T[N * 2 + 5], TT[N * 2 + 5], s[MN + 5], cnt, S[MN + 5];
pair<int, int> c[MN + 5], C[MN + 5];
bool ok;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

inline void update(int x) {
    if (T[x << 1] > T[x << 1 | 1]) {
        T[x] = T[x << 1];
        TT[x] = TT[x << 1];
    } else {
        T[x] = T[x << 1 | 1];
        TT[x] = TT[x << 1 | 1];
    }
}

void renew(int x, int v) {
    x += N;
    T[x] = v; TT[x] = x - N;
    for (; x >>= 1;) update(x);
}

int Query(int l, int r) {
    int mx = 0, where = 0;
    for(l += N - 1, r += N + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
        if ((~l&1) && T[l + 1] > mx) {
            mx = T[l + 1];
            where = TT[l + 1];
        }
        if ((r&1) && T[r - 1] > mx) {
            mx = T[r - 1];
            where = TT[r - 1];
        }
    }
    return where;
}

int build(int l, int r, int cap) {
    int x = (l == r) ? l : Query(l, r);
    // printf("build %d %d %d %d\n", l, r, x, cap);
    int base = -1;
    int new_cap = cap;
    if (a[x] != 0) {
        new_cap = min(new_cap, a[x]);
    }
    if (x > l) {
        base = max(base, build(l, x - 1, new_cap));
    }
    if (x < r) {
        base = max(base, build(x + 1, r, new_cap));
    }
    if (cap <= base || (a[x] != 0 && (a[x] >= cap || a[x] <= base))) {
        ok = false;
    }
    if (a[x] == 0) {
        // printf("add interval %d %d\n", base+1, cap-1);
        c[++cnt] = make_pair(base + 1, cap - 1);
    } else {
        base = max(base, a[x]);
    }
    return base;
}

pair<int, int> find_interval() {
    if (!ok) {
        return make_pair(1, 0);
    }
    sort(s + 1, s + m);
    sort(c + 1, c + cnt + 1);
    while(Q.size()) Q.pop();
    int mis_num = 0, mis_id = 0, matched_num = 0;
    for (int i = 1, j = 1; i < m || j <= cnt; ) {
        if (i >= m || (j <= cnt && c[j].first <= s[i])) {
            Q.push(make_pair(c[j].second, c[j].first));
            ++j;
        } else {
            while (Q.size() && Q.top().first < s[i]) {
                if (mis_num) return make_pair(1, 0);
                mis_num = 1;
                mis_id = ++matched_num;
                C[matched_num] = make_pair(Q.top().second, Q.top().first);
                // printf("GG: %d %d\n", C[matched_num].first, C[matched_num].second);
                Q.pop();
            }
            if (Q.empty()) return make_pair(1, 0);
            ++matched_num;
            S[matched_num] = s[i];
            C[matched_num] = make_pair(Q.top().second, Q.top().first);
            // printf("new match: %d  with (%d  %d)\n", S[matched_num], C[matched_num].first, C[matched_num].second);
            Q.pop();
            ++i;
        }
    }
    if (Q.size()) {
        mis_id = ++matched_num;
        C[matched_num] = make_pair(Q.top().second, Q.top().first);
        Q.pop();
    }
    // printf("find a miss: %d\n", mis_id);
    int l = C[mis_id].first, r = C[mis_id].second;
    for (int i = mis_id - 1; i; --i) {
        if (l <= S[i] && S[i] <= r) {
            l = min(l, C[i].first);
            r = max(r, C[i].second);
        } else {
            break;
        }
    }
    return make_pair(l, r);
}

int main() {
    for (int qq = read(); qq--;) {
        n = read(); q = read(); m = 0;
        for (int i = 1; i <= n; ++i) {
            p[i] = read();
            renew(i, p[i]);
        }
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
            if (a[i] == 0) {
                ++ m;
            }
        }
        for (int i = 1; i < m; ++i) {
            s[i] = read();
        }
        cnt = 0; ok = true;
        build(1, n, INF);
        pair<int, int> interval = find_interval();
        // printf("interval is %d %d\n", interval.first, interval.second);
        for (int i = 1; i <= q; ++i) {
            int x = read();
            if (x >= interval.first && x <= interval.second) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
        for (int i = 1; i <= n; ++i) {
            renew(i, 0);
        }
    }
    return 0;
}