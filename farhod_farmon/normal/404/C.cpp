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

int n, k, c[N], d[N];
vector < pair < int, int > > v, g;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    int root = -1;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
        if(d[i] == 0){
            if(root == -1)
                root = i;
            else{
                cout << -1 << endl;
                return 0;
            }
        }
        else
            g.pb({d[i], i});
    }
    if(root == -1){
        cout << -1 << endl;
        return 0;
    }
    g.pb({0, root});
    sort(g.begin(), g.end());
    int j = 0;
    for(int i = 1; i < g.size(); i++){
        while(c[j] == k || g[j].fi + 1 < g[i].fi)
            j++;
        if(g[j].fi + 1 != g[i].fi){
            cout << -1 << endl;
            return 0;
        }
        c[j]++;
        c[i]++;
        v.pb({g[j].se, g[i].se});
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i].fi << " " << v[i].se << endl;
}