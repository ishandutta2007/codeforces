#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;

int n;
int m;
int q;
int res[N];
int t[4 * N];
long long c[N];
vector < int > v[N];
vector < pair < int, int > > qu[N];

void upd(int x, int l, int r, int g, int y)
{
        if(l == r){
                t[x] += y;
                return;
        }
        int m = (l + r) / 2;
        if(g <= m) upd(x * 2, l, m, g, y);
        else upd(x * 2 + 1, m + 1, r, g, y);
        t[x] = t[x * 2] + t[x * 2 + 1];
}

int get(int x, int l, int r, int need)
{
        if(l == r){
                return l;
        }
        int m = (l + r) / 2;
        if(need <= t[x * 2]) return get(x * 2, l, m, need);
        else return get(x * 2 + 1, m + 1, r, need - t[x * 2]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> q;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                c[x] += 1;
        }
        for(int i = 1; i <= m; i++){
                v[c[i]].push_back(i);
                c[i] = 0;
        }
        for(int i = 1, all = v[0].size(); i <= n; i++){
                c[i] = c[i - 1] + all;
                all += v[i].size();
        }
        for(int i = 1; i <= q; i++){
                long long k;
                cin >> k;
                k -= n;
                int l = 0, r = n;
                while(l < r){
                        int m = (l + r) / 2;
                        if(k > c[m + 1]){
                                l = m + 1;
                        } else{
                                r = m;
                        }
                }
                k -= c[l];
                if(l == n){
                        res[i] = (k - 1) % m + 1;
                } else{
                        qu[l].push_back({k, i});
                }
        }
        for(int i = 0; i <= n; i++){
                for(int j: v[i]){
                        upd(1, 1, m, j, 1);
                }
                for(auto p: qu[i]){
                        res[p.se] = get(1, 1, m, p.fi);
                }
        }
        for(int i = 1; i <= q; i++){
                cout << res[i] << "\n";
        }
}