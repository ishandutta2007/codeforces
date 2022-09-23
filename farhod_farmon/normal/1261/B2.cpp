#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int m;
int a[N];
int res[N];
int t[N];
vector < pair < int, int > > qu[N];

void upd(int x, int g)
{
        while(x < N){
                t[x] += g;
                x += x & -x;
        }
}

int get(int k)
{
        int res = 0;
        for(int i = 20; i >= 0; i--){
                if(res + (1 << i) >= N){
                        continue;
                }
                if(t[res + (1 << i)] < k){
                        res += (1 << i);
                        k -= t[res];
                }
        }
        return res + 1;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        vector < pair < int, int > > v;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                v.push_back({a[i], i});
        }
        sort(v.begin(), v.end(), [](pair < int, int > x, pair < int, int > y){
             if(x.fi > y.fi){
                return true;
             } else if(x.fi < y.fi){
                return false;
             } else{
                return x.se < y.se;
             }
             });
        cin >> m;
        for(int i = 1; i <= m; i++){
                int k, x;
                cin >> k >> x;
                qu[k].push_back({x, i});
        }
        for(int i = 1; i <= n; i++){
                upd(v[i - 1].se, 1);
                for(auto p: qu[i]){
                        res[p.se] = get(p.fi);
                }
        }
        for(int i = 1; i <= m; i++){
                cout << a[res[i]] << "\n";
        }
}