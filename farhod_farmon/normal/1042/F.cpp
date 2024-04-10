#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000010;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
int a[N];
vector < int > v[N];
map < int, int > d[N];

void dfs(int x, int p)
{
        if(v[x].size() == 1){
                d[x][a[x]]++;
                return;
        }
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                a[y] = a[x] + 1;
                dfs(y, x);
                if(d[x].size() < d[y].size()){
                        d[x].swap(d[y]);
                }
                for(auto p: d[y]){
                        d[x][p.fi] += p.se;
                        if(p.fi + p.fi <= k + 2 * a[x]){
                                d[x][p.fi] = 1;
                        }
                }
                d[y].clear();
        }
        while(d[x].size() > 1){
                auto a = d[x].begin();
                auto b = ++d[x].begin();
                if(a->fi + b->fi <= k + 2 * ::a[x]){
                        d[x].erase(a);
                }
                else{
                        break;
                }
        }
}

void solve()
{
        cin >> n >> k;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        int s;
        for(int i = 1; i <= n; i++){
                if(v[i].size() > 1){
                        s = i;
                        break;
                }
        }
        dfs(s, s);
        int cnt = 0;
        for(auto p: d[s]){
                cnt += p.se;
        }
        cout << cnt << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}