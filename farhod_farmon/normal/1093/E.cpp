#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;
const ll mod = 998244353;

using namespace std;

int n;
int q;
int a[N];
int b[N];
vector < int > v[4 * N];

void build(int x, int l, int r)
{
        v[x].clear();
        if(l == r){
                v[x].push_back(b[l]);
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        int j = 0;
        for(int i = 0; i < v[x * 2].size(); i++){
                while(j < v[x * 2 + 1].size() && v[x * 2 + 1][j] < v[x * 2][i]){
                        v[x].push_back(v[x * 2 + 1][j]);
                        j++;
                }
                v[x].push_back(v[x * 2][i]);
        }
        while(j < v[x * 2 + 1].size()){
                v[x].push_back(v[x * 2 + 1][j]);
                j++;
        }
}

int get(int x, int l, int r, int tl, int tr, int g)
{
        if(tl > tr || v[x][0] > g){
                return 0;
        }
        if(l == tl && r == tr){
                int l = 0, r = v[x].size() - 1;
                while(l < r){
                        int m = (l + r) / 2;
                        if(v[x][m + 1] <= g){
                                l = m + 1;
                        }
                        else{
                                r = m;
                        }
                }
                return l + 1;
        }
        int m = (l + r) / 2;
        return get(x * 2, l, m, tl, min(m, tr), g) +
                get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, g);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //ios_base::sync_with_stdio(0);

        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++){
                int x;
                scanf("%d", &x);
                a[x] = i;
        }
        for(int i = 1; i <= n; i++){
                int x;
                scanf("%d", &x);
                b[i] = a[x];
        }
        build(1, 1, n);
        vector < pair < int, int > > qu;
        for(int i = 1; i <= q; i++){
                int t, l1, r1, l2, r2;
                scanf("%d", &t);
                if(t == 1){
                        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
                        int ans = get(1, 1, n, l2, r2, r1);
                        ans -= get(1, 1, n, l2, r2, l1 - 1);
                        for(int j = 0; j < qu.size(); j++){
                                int x = qu[j].fi, y = qu[j].se;
                                if(l2 <= x && x <= r2){
                                        ans -= l1 <= b[x] && b[x] <= r1;
                                }
                                if(l2 <= y && y <= r2){
                                        ans -= l1 <= b[y] && b[y] <= r1;
                                }
                                swap(b[x], b[y]);
                                if(l2 <= x && x <= r2){
                                        ans += l1 <= b[x] && b[x] <= r1;
                                }
                                if(l2 <= y && y <= r2){
                                        ans += l1 <= b[y] && b[y] <= r1;
                                }
                        }
                        for(int j = qu.size() - 1; j >= 0; j--){
                                int x = qu[j].fi, y = qu[j].se;
                                swap(b[x], b[y]);
                        }
                        printf("%d\n", ans);
                }
                else{
                        scanf("%d%d", &l1, &r1);
                        qu.push_back({l1, r1});
                }
                if(qu.size() == 1000){
                        for(auto p: qu){
                                swap(b[p.fi], b[p.se]);
                        }
                        qu.clear();
                        build(1, 1, n);
                }
        }
}