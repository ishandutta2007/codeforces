#include <bits/stdc++.h>

using namespace std;

#ifdef zxc
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug_arr(...) 42
#endif

#define fi first
#define se second

const int N = 400400;

struct fenw
{
        long long t[N];
        int c[N];

        void upd_t(int x, long long y)
        {
                while(x < N){
                        t[x] += y;
                        x += x & -x;
                }
        }
        void upd_c(int x, int y)
        {
                while(x < N){
                        c[x] += y;
                        x += x & -x;
                }
        }
        int jump(int x)
        {
                if(x == 0){
                        return 0;
                }

                int res = 0;
                for(int i = 20; i >= 0; i--){
                        if(res + (1 << i) < N && c[res + (1 << i)] < x){
                                res += (1 << i);
                                x -= c[res];
                        }
                }
                return res + 1;
        }
        long long get_t(int x)
        {
                long long res = 0;
                while(x > 0){
                        res += t[x];
                        x -= x & -x;
                }
                return res;
        }
        int get_c(int x)
        {
                int res = 0;
                while(x > 0){
                        res += c[x];
                        x -= x & -x;
                }
                return res;
        }
        long long get_with(int k)
        {
                long long res = 0, x = 0;
                for(int i = 20; i >= 0; i--){
                        if(x + (1 << i) < N && c[x + (1 << i)] <= k){
                                x += (1 << i);
                                k -= c[x];
                                res += t[x];
                        }
                }
                return res;
        }
};

int n;
int q;
int tp[N];
long long a[N], b[N];
vector < long long > V;

long long sum;
set < long long > Se;

fenw P, S;

long long t1[4 * N];
long long c1[4 * N];
long long l1[4 * N];
long long t2[4 * N];
long long c2[4 * N];
long long l2[4 * N];

void pull1(int x)
{
        c1[x] = c1[x * 2] + c1[x * 2 + 1];
        t1[x] = t1[x * 2] + t1[x * 2 + 1];
}

void pull2(int x)
{
        c2[x] = c2[x * 2] + c2[x * 2 + 1];
        t2[x] = t2[x * 2] + t2[x * 2 + 1];
}

void push1(int x)
{
        if(l1[x]){
                t1[x * 2] += c1[x * 2] * l1[x];
                t1[x * 2 + 1] += c1[x * 2 + 1] * l1[x];

                l1[x * 2] += l1[x];
                l1[x * 2 + 1] += l1[x];
                l1[x] = 0;
        }
}

void push2(int x)
{
        if(l2[x]){
                t2[x * 2] += c2[x * 2] * l2[x];
                t2[x * 2 + 1] += c2[x * 2 + 1] * l2[x];

                l2[x * 2] += l2[x];
                l2[x * 2 + 1] += l2[x];
                l2[x] = 0;
        }
}

void upd1(int x, int l, int r, int tl, int tr, long long y)
{
        if(tl > tr){
                return;
        } else if(tl == l && r == tr){
                t1[x] += c1[x] * y;
                l1[x] += y;
                return;
        }
        push1(x);
        int m = (l + r) / 2;
        upd1(x * 2, l, m, tl, min(m, tr), y);
        upd1(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
        pull1(x);
}

void upd2(int x, int l, int r, int tl, int tr, long long y)
{
        if(tl > tr){
                return;
        } else if(tl == l && r == tr){
                t2[x] += c2[x] * y;
                l2[x] += y;
                return;
        }
        push2(x);
        int m = (l + r) / 2;
        upd2(x * 2, l, m, tl, min(m, tr), y);
        upd2(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
        pull2(x);
}

long long get1(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 0;
        } else if(l == tl && r == tr){
                return t1[x];
        }
        push1(x);
        int m = (l + r) / 2;
        return get1(x * 2, l, m, tl, min(m, tr)) + get1(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

long long get2(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 0;
        } else if(l == tl && r == tr){
                return t2[x];
        }
        push2(x);
        int m = (l + r) / 2;
        return get2(x * 2, l, m, tl, min(m, tr)) + get2(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

void lp1(int x, int l, int r, int g)
{
        if(l == r){
                c1[x] ^= 1;
                if(c1[x] == 0){
                        t1[x] = 0;
                } else{
                        t1[x] = P.get_t(l - 1);
                }
                return;
        }
        push1(x);
        int m = (l + r) / 2;
        if(g <= m){
                lp1(x * 2, l, m, g);
        } else{
                lp1(x * 2 + 1, m + 1, r, g);
        }
        pull1(x);
}

void lp2(int x, int l, int r, int g)
{
        if(l == r){
                c2[x] ^= 1;
                if(c2[x] == 0){
                        t2[x] = 0;
                } else{
                        t2[x] = S.get_t(l - 1);
                }
                return;
        }
        push2(x);
        int m = (l + r) / 2;
        if(g <= m){
                lp2(x * 2, l, m, g);
        } else{
                lp2(x * 2 + 1, m + 1, r, g);
        }
        pull2(x);
}

void add(long long x)
{
        Se.insert(x);
        sum += x;
        int id = lower_bound(V.begin(), V.end(), x) - V.begin() + 1;

        P.upd_c(id, 1);
        P.upd_t(id, x);
        S.upd_t(V.size() - id + 1, x);
        S.upd_c(V.size() - id + 1, 1);

        lp1(1, 1, V.size(), id);
        lp2(1, 1, V.size(), V.size() - id + 1);

        upd1(1, 1, V.size(), id, V.size(), x);
        upd2(1, 1, V.size(), V.size() - id + 1, V.size(), x);
}

void del(long long x)
{
        Se.erase(x);
        sum -= x;
        int id = lower_bound(V.begin(), V.end(), x) - V.begin() + 1;

        P.upd_c(id, - 1);
        P.upd_t(id, - x);
        S.upd_t(V.size() - id + 1, - x);
        S.upd_c(V.size() - id + 1, - 1);

        upd1(1, 1, V.size(), id, V.size(), - x);
        upd2(1, 1, V.size(), V.size() - id + 1, V.size(), - x);

        lp1(1, 1, V.size(), id);
        lp2(1, 1, V.size(), V.size() - id + 1);

}

long long get_ans()
{
        if(Se.size() <= 1){
                return 0;
        }

        int l = (Se.size() + 1) / 2 + 1, r = Se.size();
        while(l < r){
                int m = (l + r) / 2;
                if(P.get_with(m) - S.get_with(m - 1) > 0){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        long long res = sum - *Se.begin(), X = 0, Y = 0;

        res += max(0ll, P.get_with(Se.size()) - S.get_with(Se.size() - 1));
        if(Se.size() % 2){
                res -= max(0ll, P.get_with(Se.size() / 2 + 1) - S.get_with(Se.size() / 2));
        }

        if(l <= Se.size()){
                res -= 2ll * get1(1, 1, V.size(), P.jump(l), V.size());
                res += 2ll * get2(1, 1, V.size(), max(1, S.jump(l - 1)), S.jump(Se.size() - 1));
        }

        return res;
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                V.push_back(a[i]);
        }
        for(int i = 1; i <= q; i++){
                cin >> tp[i] >> b[i];
                V.push_back(b[i]);
        }
        sort(V.begin(), V.end());
        vector < long long > nv;
        for(auto x: V){
                if(nv.empty() || x > nv.back()){
                        nv.push_back(x);
                }
        }
        V = nv;

        for(int i = 1; i <= n; i++){
                add(a[i]);
        }

        cout << get_ans() << "\n";

        for(int i = 1; i <= q; i++){
                if(tp[i] == 1){
                        add(b[i]);
                } else{
                        del(b[i]);
                }

                cout << get_ans() << "\n";
        }
}