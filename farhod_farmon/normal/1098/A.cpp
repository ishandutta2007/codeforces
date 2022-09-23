#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 9;

using namespace std;

int n;
long long a[N];
long long res;
vector < int > v[N];

void dfs(int x, long long last)
{
        if(v[x].empty()){
                return;
        }
        if(a[x] == -1){
                long long mn = 1e9;
                for(int y: v[x]){
                        mn = min(mn, a[y]);
                }
                if(mn < last){
                        cout << -1 << "\n";
                        exit(0);
                }
                res += mn - last;
                for(int y: v[x]){
                        res += a[y] - mn;
                        dfs(y, last);
                }
        }
        else{
                for(int y: v[x]){
                        dfs(y, a[x]);
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 2; i <= n; i++){
                int x;
                cin >> x;
                v[x].push_back(i);
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        res = a[1];
        dfs(1, 0);
        cout << res << "\n";
}