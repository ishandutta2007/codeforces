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

vector < int > v;
vector < pair < int, int > > g;
int n, a[N], s[3][N];

int get(int i, int x)
{
    if(max(s[1][n] - s[1][i - 1], s[2][n] - s[2][i - 1]) < x)
        return -1;
    int l = i,
        r = n;
    while(l < r){
        int m = (l + r) / 2;
        if(max(s[1][m] - s[1][i - 1], s[2][m] - s[2][i - 1]) < x)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int can(int x)
{
    int w[3] = {0, 0, 0};
    for(int i = 1; i <= n;){
        int h = get(i, x);
        if(h == -1)
            return -1;
        if(s[1][h] - s[1][i - 1] == x)
            w[1]++;
        else
            w[2]++;
        if(h == n){
            if(w[a[n]] > w[3 - a[n]])
                return w[a[n]];
        }
        i = h + 1;
    }
    return -1;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[1][i] = s[1][i - 1];
        s[2][i] = s[2][i - 1];
        s[a[i]][i]++;
    }
    for(int i = 1; i <= n; i++){
        int t = can(i);
        if(t != -1)
            g.pb({t, i});
    }
    sort(g.begin(), g.end());
    cout << g.size() << endl;
    for(int i = 0; i < g.size(); i++)
        cout << g[i].fi << " " << g[i].se << endl;
}