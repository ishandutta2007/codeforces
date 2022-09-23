#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 500500;
const int mod = 1e9 + 7;

using namespace std;

int n, q, k;
int p[N], s[N];
vector < pair < int, int > > t[4 * N];

void upd(int x, int l, int r, int tl, int tr, pair < int, int > y)
{
        if(tl > tr){
                return;
        } else if(l == tl && r == tr){
                t[x].push_back(y);
                return;
        }
        int m = (l + r) / 2;
        upd(x * 2, l, m, tl, min(m, tr), y);
        upd(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, y);
}

vector < pair < int*, int > > bc;

int get(int x){ return p[x] == x ? x : get(p[x]); }

void make(int x, int y)
{
        x = get(x);
        y = get(y);
        if(x == y){
                return;
        }
        if(s[x] < s[y]){
                swap(x, y);
        }
        bc.push_back({&s[x], s[x]});
        bc.push_back({&p[y], p[y]});
        p[y] = x;
        s[x] += s[y];
}

vector < int > qu[N];

void solve(int x, int l, int r)
{
        int len = bc.size();
        for(auto p: t[x]){
                make(p.fi, p.se);
        }
        if(l == r){
                for(int x: qu[l]){
                        printf("%d\n", s[get(x)]);
                }
        } else{
                int m = (l + r) / 2;
                solve(x * 2, l, m);
                solve(x * 2 + 1, m + 1, r);
        }
        while(bc.size() > len){
                (*bc.back().fi) = bc.back().se;
                bc.pop_back();
        }
}

pair < int, int > A[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        scanf("%d%d%d", &n, &q, &k);
        vector < int > f(q + 1, 0);
        for(int i = 1; i <= q; i++){
                int t, x, y;
                scanf("%d", &t);
                if(t == 1){
                        scanf("%d%d", &x, &y);
                        A[i] = {x, y};
                } else if(t == 2){
                        scanf("%d", &x);
                        qu[i].push_back(x);
                } else{
                        f[i] = 1;
                }
        }
        for(int i = 1, j = 1, cnt = f[1]; i <= q; i++){
                while(cnt < k && j < q){
                        j += 1;
                        cnt += f[j];
                }
                if(A[i].fi > 0){
                        upd(1, 1, q, i, j, A[i]);
                }
                cnt -= f[i];
        }
        for(int i = 1; i <= n; i++){
                p[i] = i;
                s[i] = 1;
        }
        solve(1, 1, q);
}