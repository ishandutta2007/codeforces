#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;
const ll mod = 998244353;

using namespace std;

int n;
int m;
int q;
int p[N];
int s[N];

int get(int x)
{
        if(p[x] == x){
                return x;
        }
        return p[x] = get(p[x]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> q;
        for(int i = 1; i <= n; i++){
                p[i] = i;
        }
        for(int i = 1; i <= q; i++){
                int x;
                cin >> x;
                s[x] = 1;
        }
        int ans = 0;
        vector < pair < int, pair < int, int > > > v;
        for(int i = 1; i <= m; i++){
                int x, y, w;
                cin >> x >> y >> w;
                v.push_back({w, {x, y}});
        }
        sort(v.begin(), v.end());
        for(auto gg: v){
                int x = gg.se.fi, y = gg.se.se, w = gg.fi;
                x = get(x);
                y = get(y);
                if(x == y){
                        continue;
                }
                if(s[x] && s[y]){
                        ans = w;
                }
                p[x] = y;
                s[y] |= s[x];
        }
        for(int i = 1; i <= q; i++){
                cout << ans << " ";
        }
}