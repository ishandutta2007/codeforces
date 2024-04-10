#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 500005;
const int MX = 10010;

using namespace std;

int n;
string s;
vector < int > edge[N];
vector < pair < string, int > > v;
vector < string > dip[N];
bool used[N];

void dfs(int x, int g)
{
    used[x] = true;
    n = max(n, g);
    dip[g].pb(v[x].fi);
    for(auto y: edge[x])
        if(!used[y])
            dfs(y, g + 1);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    s += ',';
    for(int i = 0; i < s.size(); i++){
        string t = "";
        int x = 0;
        int j = i;
        while(s[j] != ','){
            t += s[j];
            j++;
        }
        j++;
        while(s[j] != ','){
            x = x * 10 + s[j] - '0';
            j++;
        }
        v.pb({t, x});
        i = j;
    }
    vector < int > g;
    for(int i = 0; i < v.size(); i++){
        if(!g.empty()){
            edge[g.back()].pb(i);
            v[g.back()].se--;
        }
        g.pb(i);
        while(!g.empty() && v[g.back()].se == 0)
            g.pop_back();
    }
    for(int i = 0; i < v.size(); i++)
        if(!used[i])
            dfs(i, 1);
    cout << n << endl;
    for(int i = 1; i <= n; i++){
        for(auto x: dip[i])
            cout << x << " ";
        cout << "\n";
    }
}