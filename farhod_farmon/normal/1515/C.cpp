#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

void solve()
{
        int n, m, x;
        cin >> n >> m >> x;
        vector < pair < int, int > > a(n);
        vector < int > res(n);
        for(int i = 0; i < n; i++){
                cin >> a[i].fi;
                a[i].se = i;
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++){
                res[a[i].se] = i % m;
        }
        cout << "YES\n";
        for(int x: res){
                cout << x + 1 << " ";
        }
        cout << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}