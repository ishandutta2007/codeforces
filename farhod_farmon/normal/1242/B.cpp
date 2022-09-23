#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 1e9 + 7;

using namespace std;

int n;
int m;
set < int > s;
vector < int > v[N];

void dfs(int x)
{
        s.erase(x);
        int l = v[x].size();
        for(int i = 0; i < l - 1 && !s.empty(); i++){
                auto p = s.lower_bound(v[x][i] + 1);
                if(p == s.end()){
                        break;
                } else if(*p >= v[x][i + 1]){
                        continue;
                }
                dfs(*p);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        for(int i = 1; i <= n; i++){
                s.insert(i);
                v[i].push_back(0);
                v[i].push_back(n + 1);
                sort(v[i].begin(), v[i].end());
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
                if(s.find(i) != s.end()){
                        dfs(i);
                        res += 1;
                }
        }
        cout << res - 1 << '\n';
}