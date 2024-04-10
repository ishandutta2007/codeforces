#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;
int res[N];
pair < pair < int, int >, int > a[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi.fi >> a[i].fi.se;
                a[i].se = i;
        }
        sort(a + 1, a + n + 1);
        int r = a[1].fi.se;
        for(int i = 2; i <= n; i++){
                if(r < a[i].fi.fi){
                        for(int j = 1; j < i; j++){
                                res[a[j].se] = 1;
                        }
                        for(int j = i; j <= n; j++){
                                res[a[j].se] = 2;
                        }
                        break;
                }
                r = max(r, a[i].fi.se);
                if(i == n){
                        cout << -1 << "\n";
                        return;
                }
        }
        for(int i = 1; i <= n; i++){
                cout << res[i] << " \n"[i == n];
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}