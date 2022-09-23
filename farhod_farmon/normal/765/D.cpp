#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int f[N];
int g[N];
int h[N];
vector < int > v[N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> f[i];
        v[f[i]].pb(i);
    }
    for(int i = 1; i <= n; i++){
        bool b = false;
        if(v[i].empty())
            continue;
        for(int x: v[i])
            if(x == i)
                b = true;
        if(!b){
            cout << -1 << endl;
            return;
        }
        m++;
        h[m] = i;
        for(int x: v[i])
            g[x] = m;
    }
    cout << m << endl;
    for(int i = 1; i <= n; i++)
        cout << g[i] << " ";
    cout << endl;
    for(int i = 1; i <= m; i++)
        cout << h[i] << " ";
    cout << endl;
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}