#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 2002 * 50;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int q;
int a[N];
int t[4 * N];

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = a[l];
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = min(t[x * 2], t[x * 2 + 1]);
}

void upd(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                t[x] = 1e9;
                return;
        }
        if(t[x] == 1e9){
                t[x * 2] = t[x * 2 + 1] = 1e9;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr));
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
        t[x] = min(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 1e9;
        }
        if(l == tl && r == tr){
                return t[x];
        }
        if(t[x] == 1e9){
                t[x * 2] = t[x * 2 + 1] = 1e9;
        }
        int m = (l + r) / 2;
        return min(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

int l[N];
int r[N];
int ans[N];
set < int > s;

void solve()
{
        cin >> n >> q;
        for(int i = 1; i <= q; i++){
                l[i] = n + 1;
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                ans[i] = 1;
                s.insert(i);
                l[a[i]] = min(l[a[i]], i);
                r[a[i]] = max(r[a[i]], i);
                if(a[i] == 0){
                        a[i] = 1e9;
                }
        }
        if(r[q] == 0){
                for(int i = 1; i <= n; i++){
                        if(a[i] == 1e9){
                                a[i] = q;
                                l[q] = r[q] = i;
                                break;
                        }
                }
                if(r[q] == 0){
                        cout << "NO" << "\n";
                        return;
                }
        }
        build(1, 1, n);
        for(int i = q; i >= 1; i--){
                if(r[i] == 0){
                        continue;
                }
                int g = get(1, 1, n, l[i], r[i]);
                if(g < i){
                        cout << "NO" << "\n";
                        return;
                }
                upd(1, 1, n, l[i], r[i]);
                auto p = s.lower_bound(l[i]);
                while(p != s.end() && *p <= r[i]){
                        ans[*p] = i;
                        s.erase(p);
                        p = s.lower_bound(l[i]);
                }
        }
        cout << "YES" << "\n";
        for(int i = 1; i <= n; i++){
                cout << ans[i] << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}