#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 200200;

int n;
int a[N];
long long res[N];
long long s[N];
vector < int > v[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                v[i].clear();
                res[i] = 0;
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                v[a[i]].push_back(x);
        }
        for(int i = 1; i <= n; i++){
                if(v[i].empty()){
                        continue;
                }
                sort(v[i].begin(), v[i].end());
                reverse(v[i].begin(), v[i].end());
                int m = v[i].size();
                for(int j = 1; j <= m; j++){
                        s[j] = s[j - 1] + v[i][j - 1];
                }
                for(int j = 1; j <= m; j++){
                        res[j] += s[m / j * j];
                }
        }

        for(int i = 1; i <= n; i++){
                cout << res[i] << " ";
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