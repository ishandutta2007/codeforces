#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int m;
int q;
long long a[N];
long long b[N];
long long all;

long long t[4 * N];
long long s[4 * N];
long long lz[4 * N];

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = b[l] - b[l - 1];
                s[x] = b[l] - b[l - 1];
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = t[x * 2 + 1];
        s[x] = s[x * 2] + s[x * 2 + 1];
}

void push(int x, int l, int m, int r)
{
        if(lz[x]){
                t[x * 2] += lz[x];
                s[x * 2] += lz[x] * (m - l + 1);
                t[x * 2 + 1] += lz[x];
                s[x * 2 + 1] += lz[x] * (r - m);
                lz[x * 2] += lz[x];
                lz[x * 2 + 1] += lz[x];
                lz[x] = 0;
        }
}

void upd(int x, int l, int r, int tl, int tr, long long y)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                t[x] += y;
                s[x] += y * (r - l + 1);
                lz[x] += y;
                return;
        }
        int m = (l + r) / 2;
        push(x, l, m, r);
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
        t[x] = t[x * 2 + 1];
        s[x] = s[x * 2] + s[x * 2 + 1];
}

int get(int x, int l, int r, long long y)
{
        if(l == r){
                return l;
        }
        int m = (l + r) / 2;
        push(x, l, m, r);
        if(t[x * 2] < y){
                return get(x * 2 + 1, m + 1, r, y);
        } else{
                return get(x * 2, l, m, y);
        }
}

long long get_real(int x, int l, int r, int g)
{
        if(l == r){
                return s[x];
        }
        int m = (l + r) / 2;
        push(x, l, m, r);
        if(g <= m){
                return get_real(x * 2, l, m, g);
        } else{
                return get_real(x * 2 + 1, m + 1, r, g) + s[x * 2];
        }
}

long long solve()
{
        long long res = all;
        int j = 1;
        for(int i = 1; i < n; i++){
                int h;
                if(t[1] < a[i + 1] - a[i]){
                        h = m;
                } else{
                        h = get(1, 1, m, a[i + 1] - a[i]) - 1;
                }

                h = max(h, j);
                res += a[i] * (h - j + 1);
                j = h;
                res += get_real(1, 1, m, j);
        }
        res += a[n] * (m - j + 1);
        return res;
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
                cin >> b[i];
                all += b[i];
        }
        build(1, 1, m);
        for(int i = 1; i <= q; i++){
                int t, x, y;
                cin >> t >> x >> y;
                if(t == 1){
                        for(int j = n - x + 1; j <= n; j++){
                                a[j] += y * (j - (n - x));
                        }
                } else{
                        upd(1, 1, m, m - x + 1, m, y);
                        all += 1ll * x * (x + 1) / 2 * y;
                }
                cout << solve() << "\n";
        }
}