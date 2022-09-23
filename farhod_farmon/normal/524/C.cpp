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

int n, k;
vector < pair < int, int > > v;
map < int, int > d;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    d[0] = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for(int j = 1; j <= k; j++){
            v.pb({x * j, j});
            if(d.find(x * j) == d.end())
                d[x * j] = j;
            else
                d[x * j] = min(d[x * j], j);
        }
    }
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
        int x,
            ans = 1e9;
        cin >> x;
        for(int j = 0; j < v.size(); j++){
            if(x >= v[j].fi && d.find(x - v[j].fi) != d.end())
                ans = min(ans, v[j].se + d[x - v[j].fi]);
        }
        if(ans > k)
            ans = -1;
        cout << ans << endl;
    }
}