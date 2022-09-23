#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int Q = 1 << 21;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int a[N];
int b[N];
vector < int > g[N];
vector < int > v[N];

bool can(int k)
{
        for(int i = 0; i < N; i++){
                v[i].clear();
        }
        for(int i = 1; i <= n; i++){
                b[i] = a[i];
                int best = 0;
                for(int x: g[i]){
                        if(x <= k){
                                best = max(best, x);
                        }
                }
                v[best].push_back(i);
        }
        int money = 0;
        for(int i = 1; i <= k; i++){
                money += 1;
                for(int x: v[i]){
                        int g = min(money, b[x]);
                        money -= g;
                        b[x] -= g;
                }
        }
        for(int i = 1; i <= n; i++){
                money -= b[i] * 2;
        }
        return money >= 0;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                g[y].push_back(x);
        }
        int l = 1, r = 4e5 + 100;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m)){
                        r = m;
                } else{
                        l = m + 1;
                }
        }
        cout << l << "\n";
}