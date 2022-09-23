#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 110;

using namespace std;

vector < int > v[N];
bool used[N];
int n, m, l, L[N];

void dfs(int x, int p, int g)
{
    if(used[x]){
        if(!l)
            l = g - L[x];
        return;
    }
    L[x] = g;
    used[x] = true;
    for(int i = 0; i < v[x].size(); i++)
        if(v[x][i] != p)
            dfs(v[x][i], x, g + 1);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    if(m != n){
        cout << "NO" << endl;
        return 0;
    }
    dfs(1, 1, 1);
    for(int i = 1; i <= n; i++){
        if(l < 3 || used[i] == false){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "FHTAGN!" << endl;
}