#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1000100;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int tim;
int t[N];
int tin[N];
int tout[N];
int h1;
int h2;
int mx = 0;
int mn = 1e9;
int s;
int ans[N];
vector < int > v[N];

void dfs(int x)
{
    tin[x] = ++tim;
    for(int y: v[x]){
        dfs(y);
        t[x] += t[y];
        ans[x] = max(ans[x], ans[y]);
    }
    tout[x] = ++tim;
    if(t[x] * 3 == s * 2 && ans[x] && x != v[0][0]){
        cout << x << " " << ans[x] << endl;
        exit(0);
    }
    if(t[x] == s / 3 && x != v[0][0]){
        if(tout[x] < mn){
            mn = tout[x];
            h1 = x;
        }
        if(tin[x] > mx){
            mx = tin[x];
            h2 = x;
        }
        ans[x] = x;
    }
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x >> t[i];
        s += t[i];
        v[x].pb(i);
    }
    if(s % 3){
        cout << -1 << endl;
        return;
    }
    dfs(v[0][0]);
    if(mn < mx){
        cout << h1 << " " << h2 << endl;
    }
    else{
        cout << -1 << endl;
    }
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