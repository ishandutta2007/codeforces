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

set < int > s[N];
int n, m, c[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        s[c[i]].insert(c[i]);
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        x = c[x];
        y = c[y];
        s[x].insert(y);
        s[y].insert(x);
    }
    int mx = N - 1;
    for(int i = N - 1; i >= 1; i--)
        if(s[i].size() > s[mx].size() || s[i].size() == s[mx].size() && i < mx)
            mx = i;
    cout << mx << endl;
}