#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10001;
const long long mod = 1e9 + 7;;
const long long block = sqrt(N);

using namespace std;

int n;
int p[N];
int ans;
int best[N];
long long rl[N];
long long L;
long long S;
long long w[N];
long long c[N];
vector < int > g;
vector < int > v[N];

void dfs(int x)
{
        g.push_back(x);
        int go = 1e9;
        for(int y: v[x]){
                dfs(y);
                go = min(go, best[y]);
        }
        if(go <= g.size()){
                best[x] = go;
        }
        else{
                ans++;
                int l = 0, r = g.size() - 1;
                while(l < r){
                        int m = (l + r) / 2;
                        if(w[x] - w[g[m]] + rl[g[m]] <= S && c[x] - c[g[m]] < L){
                                r = m;
                        }
                        else{
                                l = m + 1;
                        }
                }
                best[x] = l + 1;
        }
        g.pop_back();
}

void solve()
{
        cin >> n >> L >> S;
        for(int i = 1; i <= n; i++){
                cin >> w[i];
                rl[i] = w[i];
                if(w[i] > S){
                        cout << -1 << "\n";
                        return;
                }
        }
        for(int i = 2; i <= n; i++){
                cin >> p[i];
                v[p[i]].push_back(i);
                w[i] += w[p[i]];
                c[i] += c[p[i]] + 1;
        }
        dfs(1);
        cout << ans << "\n";
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