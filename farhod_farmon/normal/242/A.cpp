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

vector < pair < int, int > > v;
int x, y, a, b;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> x >> y >> a >> b;
    for(int i = a; i <= x; i++){
        for(int j = b; j <= y; j++){
            if(i > j)
                v.pb({i, j});
        }
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i].fi << " " << v[i].se << endl;
}