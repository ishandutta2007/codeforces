#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n, k;
char a[N];
int c[26];
bool used[N];
vector < int > v[N];

void dfs(int x)
{
        if(used[x]) return;
        used[x] = true;
        c[a[x]] += 1;
        for(int y: v[x]) dfs(y);
}

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] -= 'a';
        }
        for(int i = 1; i <= n; i++) v[i].clear();
        for(int i = 1; i + k <= n; i++){
                v[i].push_back(i + k);
                v[i + k].push_back(i);
        }
        for(int i = 1; i <= n; i++) v[i].push_back(n - i + 1);

        for(int i = 1; i <= n; i++) used[i] = 0;
        int res = n;
        for(int i = 1; i <= n; i++){
                if(used[i]) continue;
                for(int j = 0; j < 26; j++) c[j] = 0;
                dfs(i);
                int mx = 0;
                for(int j = 0; j < 26; j++) mx = max(mx, c[j]);
                res -= mx;
        }
        cout << res << '\n';
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--) solve();
}