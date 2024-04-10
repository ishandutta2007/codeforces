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

int n, q, k, s, t;
bool vol[N];
vector < int > v[N];
int d[N];

bool can(int m)
{
    for(int i = 1; i <= n; i++)
        d[i] = 1e9;
    d[s] = 0;
    queue < pair < int, int > > q;
    q.push({s, 0});
    while(!q.empty()){
        int x = q.front().fi,
            l = q.front().se;
        q.pop();
        if(l > d[x])
            continue;
        if(l == m)
            continue;
        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i];
            if(d[x] + 1 < d[y]){
                d[y] = d[x] + 1;
                if(vol[y])
                    d[y] = 0;
                q.push({y, d[y]});
            }
        }
    }
    return d[t] < 1e9;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> q >> k;
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        vol[x] = true;
    }
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    cin >> s >> t;
    int l = 1,
        r = n;
    while(l < r){
        int m = (l + r) / 2;
        if(can(m))
            r = m;
        else
            l = m + 1;
    }
    if(!can(l))
        l = -1;
    cout << l << endl;
}