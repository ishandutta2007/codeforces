#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr prlong longf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n;
int p[N];
long long mod = 1e9 + 7;
bool used[N];
vector < int > v[N], vr[N], order, comp;

void dfs1(int x)
{
    used[x] = true;
    for(auto y: v[x])
        if(!used[y])
            dfs1(y);
    order.pb(x);
}

void dfs2(int x)
{
    used[x] = true;
    comp.pb(p[x]);
    for(auto y: vr[x])
        if(!used[y])
            dfs2(y);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        vr[y].pb(x);
    }
    for(int i = 1; i <= n; i++)
        if(!used[i])
            dfs1(i);
    for(int i = 1; i <= n; i++)
        used[i] = false;
    long long ans = 0,
              cnt = 1;
    for(int i = n - 1; i >= 0; i--){
        if(!used[order[i]]){
            comp.clear();
            dfs2(order[i]);
            sort(comp.begin(), comp.end());
            for(int j = 0; j < comp.size(); j++){
                if(j + 1 < comp.size() && comp[j + 1] == comp[j])
                    continue;
                ans += comp[j];
                cnt = (1ll * cnt * (j + 1)) % mod;
                break;
            }
        }
    }
    cout << ans << " " << cnt << endl;
}