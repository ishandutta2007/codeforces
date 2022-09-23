#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int k;
int a[N];
int b[N];
int w[N];
int p[N];
long long d[N];
vector < int > v[N], g;

void dfs(int x)
{
        for(int i: v[x]){
                int y = a[i] ^ b[i] ^ x;
                if(p[y] == i && k){
                        k--;
                        g.push_back(i);
                        dfs(y);
                }
        }
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 1; i <= m; i++){
                cin >> a[i] >> b[i] >> w[i];
                v[a[i]].push_back(i);
                v[b[i]].push_back(i);
        }
        for(int i = 2; i <= n; i++){
                d[i] = 1e18;
        }
        set < pair < long long, int > > s;
        s.insert({0, 1});
        while(!s.empty()){
                int x = s.begin()->se;
                s.erase(s.begin());
                for(auto i: v[x]){
                        int y = a[i] ^ b[i] ^ x;
                        if(d[x] + w[i] < d[y]){
                                s.erase({d[y], y});
                                d[y] = d[x] + w[i];
                                p[y] = i;
                                s.insert({d[y], y});
                        }
                }
        }
        dfs(1);
        cout << g.size() << "\n";
        for(int x: g){
                cout << x << " ";
        }
}