#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

vector < pair < int, int > > res;

void solve(int l, int r)
{
        if(l == r){
                return;
        }
        int m = (l + r) / 2;
        solve(l, m);
        solve(m + 1, r);
        for(int i = l; i <= m; i++){
                res.push_back({i, m + (i - l + 1)});
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        if(n <= 2){
                cout << 0 << "\n";
                return 0;
        }
        int k = 1;
        while(k * 2 < n){
                k *= 2;
        }
        solve(1, k);
        solve(n - k + 1, n);
        cout << res.size() << "\n";
        for(auto p: res) cout << p.fi << " " << p.se << "\n";
}