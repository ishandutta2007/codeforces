#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int n;
vector < int > v[3];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        v[x - 1].pb(i);
    }
    int g = min(v[0].size(), min(v[1].size(), v[2].size()));
    cout << g << endl;
    for(int i = 0; i < g; i++)
        cout << v[0][i] << " " << v[1][i] << " " << v[2][i] << endl;
}