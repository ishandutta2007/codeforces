#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int cl[N];
int cr[N];
long long res;

void solve(int l, int r)
{
        if(l >= r){
                return;
        }
        int m = (l + r) / 2;

        solve(l, m - 1);
        solve(m + 1, r);

        vector < pair < int, int > > v;

        for(int i = m; i <= r; i++){
                int x = a[i];
                if(i > m){
                        x = max(x, v.back().fi);
                }
                v.push_back({x, a[i]});
        }
        for(int i = m; i >= l; i--){
                int x = a[i];
                if(i < m){
                        x = max(x, v.back().fi);
                }
                v.push_back({x, - a[i]});
        }

        sort(v.begin(), v.end());
        for(auto p: v){
                if(p.se > 0){
                        res += cl[p.fi - p.se];
                        cr[p.se] += 1;
                } else{
                        res += cr[p.fi + p.se];
                        cl[-p.se] += 1;
                }
        }

        for(auto p: v){
                if(p.se > 0){
                        cr[p.se] -= 1;
                } else{
                        cl[-p.se] -= 1;
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }

        solve(1, n);

        cout << res << "\n";
}