#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
int m;
int d[N];
int p[N];
int lz[N * 8];
int t[N * 8];
vector<int> v[N];
pair<int, int> a[N];

int comb(int x, int y)
{
        return d[x] > d[y] ? x : y;
}

void push(int x)
{
        if(lz[x]){
                t[x * 2] = comb(t[x * 2], lz[x]);
                t[x * 2 + 1] = comb(t[x * 2 + 1], lz[x]);
                lz[x * 2] = comb(lz[x * 2], lz[x]);
                lz[x * 2 + 1] = comb(lz[x * 2 + 1], lz[x]);
                lz[x] = 0;
        }
}

void upd(int x, int l, int r, int tl, int tr, int y)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                t[x] = comb(t[x], y);
                lz[x] = comb(lz[x], y);
                return;
        }
        push(x);
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);

        t[x] = comb(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 0;
        } else if(tl == l && tr == r){
                return t[x];
        }
        push(x);
        int m = (l + r) / 2;
        return comb(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        vector<int> ord;
        for(int i = 1; i <= m; i++){
                int x;
                cin >> x >> a[i].fi >> a[i].se;
                v[x].push_back(i);
                ord.push_back({a[i].fi});
                ord.push_back({a[i].se});
        }
        sort(ord.begin(), ord.end());
        map<int, int> M;
        for(int i = 0, j = 1; i < 2 * m; i++){
                if(i && ord[i] != ord[i - 1]){
                        j += 1;
                }
                M[ord[i]] = j;
        }
        for(int i = 1; i <= m; i++){
                a[i].fi = M[a[i].fi];
                a[i].se = M[a[i].se];
        }

        for(int i = 1; i <= n; i++){
                for(int j: v[i]){
                        p[i] = comb(p[i], get(1, 1, 2 * m, a[j].fi, a[j].se));
                }
                d[i] = d[p[i]] + 1;
                for(int j: v[i]){
                        upd(1, 1, 2 * m, a[j].fi, a[j].se, i);
                }
        }
        int h = 1;
        for(int i = 1; i <= n; i++){
                h = comb(h, i);
        }
        vector<int> used(n + 1, 0);
        while(h){
                used[h] = true;
                h = p[h];
        }
        vector<int> res;
        for(int i = 1; i <= n; i++){
                if(!used[i]){
                        res.push_back(i);
                }
        }
        cout << res.size() << "\n";
        for(int x : res){
                cout << x << " ";
        }
}