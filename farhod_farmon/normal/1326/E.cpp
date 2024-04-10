#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int inf = 1e8;

struct seg
{
        int lz[4 * N];
        pair < int, int > t[4 * N];

        void build(int x, int l, int r, int *a)
        {
                lz[x] = 0;
                if(l == r){
                        t[x] = {a[l], - l};
                        return;
                }
                int m = (l + r) / 2;
                build(x * 2, l, m, a);
                build(x * 2 + 1, m + 1, r, a);
                t[x] = max(t[x * 2], t[x * 2 + 1]);
        }
        void upd(int x, int l, int r, int tl, int tr, int y)
        {
                if(tl > tr) return;
                else if(l == tl && r == tr){
                        t[x].fi += y;
                        lz[x] += y;
                        return;
                }
                int m = (l + r) / 2;
                upd(x * 2, l, m, tl, min(m,tr), y);
                upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
                t[x] = max(t[x * 2], t[x * 2 + 1]);
                t[x].fi += lz[x];
        }

        pair < int, int > get(int x, int l, int r, int tl, int tr)
        {
                if(tl > tr) return {-inf, 0};
                else if(l == tl && r == tr) return t[x];
                int m = (l + r) / 2;
                auto ans = max(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
                ans.fi += lz[x];
                return ans;
        }
};

int n;
int a[N], b[N];
bool dead[N];
seg A, B;

int last;

int sol()
{
        while(dead[last]) last--;
        return last;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);


        cin >> n;
        B.build(1, 1, n, a);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        A.build(1, 1, n, a);

        last = n;
        cout << sol() << " ";
        for(int i = 1; i < n; i++){
                int pos = b[i];
                B.upd(1, 1, n, pos, n, 1);
                int j = - B.t[1].se;

                int h = - A.get(1, 1, n, 1, j).se;
                //cout << j << ' ' << h << "\n";
                A.upd(1, 1, n, h, h, - a[h]);
                B.upd(1, 1, n, h, n, -1);
                dead[a[h]] = true;

                cout << sol() << " ";
         }
}