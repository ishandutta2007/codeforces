#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 550;

using namespace std;

int n, k, a[N], b[N];
int s[N];
vector < pair < char, int > > ans;

void f(int l, int r, int gg)
{
    vector < int > g;
    for(int i = l; i <= r; i++)
        g.pb(a[i]);
    while(g.size() > 1){
        int mx = 0;
        for(int i = 0; i < g.size(); i++)
            mx = max(mx, g[i]);
        bool bb = false;
        for(int i = 0; i < g.size(); i++){
            if(g[i] != mx)
                continue;
            if(i - 1 >= 0 && g[i - 1] < g[i]){
                bb = true;
                ans.pb({'L', gg + i});
                vector < int > ng;
                g[i] += g[i - 1];
                for(int j = 0; j < g.size(); j++){
                    if(j == i - 1)
                        continue;
                    ng.pb(g[j]);
                }
                g = ng;
                break;
            }
            if(i + 1 < g.size() && g[i + 1] < g[i]){
                bb = true;
                ans.pb({'R', gg + i});
                vector < int > ng;
                g[i] += g[i + 1];
                for(int j = 0; j < g.size(); j++){
                    if(j == i + 1)
                        continue;
                    ng.pb(g[j]);
                }
                g = ng;
                break;
            }
        }
        if(!bb){
            cout << "NO" << endl;
            exit(0);
        }
    }
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] += s[i - 1] + a[i];
    }
    cin >> k;
    for(int j = 1; j <= k; j++)
        cin >> b[j];
    int last = 0, j = 1;
    for(int i = 1; i <= n; i++){
        if(j > k){
            cout << "NO" << endl;
            return 0;
        }
        if(s[i] - s[last] < b[j])
            continue;
        if(s[i] - s[last] != b[j]){
            cout << "NO" << endl;
            return 0;
        }
        f(last + 1, i, j);
        last = i;
        j = j + 1;
    }
    if(j != k + 1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(auto x: ans)
        cout << x.se << " " << x.fi << endl;
}