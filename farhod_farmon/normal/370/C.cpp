#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 5050;

using namespace std;

int n, m;
int a[N], g, f[N];
set < int > s[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        f[a[i]]++;
        if(f[a[i]] > f[g])
            g = a[i];
    }
    for(int i = 1; i <= f[g]; i++)
        s[i].insert(g);
    for(int i = 1; i <= n; i++){
        if(a[i] == g)
            continue;
        bool b = false;
        for(int j = 1; j <= f[g] && !b; j++){
            if(s[j].size() > 1)
                continue;
            s[j].insert(a[i]);
            b = true;
        }
        if(b)
            continue;
        for(int j = 1; j <= f[g] && !b; j++){
            if(s[j].find(a[i]) == s[j].end()){
                b = true;
                s[j].insert(a[i]);
            }
        }
    }
    int cnt = 0;
    vector < pair < int, int > > ans;
    for(int i = 1; i <= f[g]; i++){
        vector < int > v;
        for(auto &x: s[i])
            v.pb(x);
        int g = v.size();
        for(int j = 0; j < g; j++){
            ans.pb({v[j], v[(j + 1) % g]});
        }
        if(g > 1)
            cnt += g;
    }
    cout << cnt << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].fi << " " << ans[i].se << endl;
}