#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100100;

using namespace std;

int n, i, j, h, cnt;
vector < pair < int, int > > v;
vector < int > p[N];
bool used[N], take[N];

int main()
{
    cin >> n;
    for( i = 2; i <= n; i++ ){
        if( used[i] )
            continue;
        p[i].pb(i);
        for( j = i + i; j <= n; j += i ){
            used[j] = true;
            p[i].pb(j);
        }
    }
    for( i = 3; i <= n / 2; i++ ){
        if( used[i] )
            continue;
        h = 0;
        for( j = 0; j < p[i].size(); j++ ){
            if( !take[p[i][j]] )
                h++;
        }
        int last = -1;
        for( j = 0; j < p[i].size(); j++ ){
            if( p[i][j] == 2 * i && h % 2 == 1 || take[p[i][j]] )
                continue;
            if( last == -1 )
                last = p[i][j];
            else{
                v.pb(mp(last, p[i][j]));
                take[last] = take[p[i][j]] = true;
                last = -1;
            }
        }
    }
    int last = -1;
    for( i = 0; i < p[2].size(); i++ ){
        int x = p[2][i];
        if( take[x] )
            continue;
        if( last == -1 )
            last = x;
        else{
            take[last] = take[x] = true;
            v.pb(mp(last, x));
            last = -1;
        }
    }
    cout << v.size() << endl;
    for( i = 0; i < v.size(); i++ )
        cout << v[i].fi << " " << v[i].se << endl;
}