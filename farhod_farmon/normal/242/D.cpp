#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

vector < int > v[N], g, q;
int n, m, a[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0)
            q.pb(i);
    }
    for(int i = 0; i < q.size(); i++){
        int x = q[i];
        if(a[x] != 0)
            continue;
        g.pb(x);
        a[x]--;
        for(int j = 0; j < v[x].size(); j++){
            int y = v[x][j];
            a[y]--;
            if(a[y] == 0)
                q.pb(y);
        }
    }
    cout << g.size() << endl;
    for(int i = 0; i < g.size(); i++)
        cout << g[i] << " ";
}