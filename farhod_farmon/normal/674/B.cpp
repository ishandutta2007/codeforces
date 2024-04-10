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

using namespace std;

int n, k, i, j, h, a, b, c, d, cnt;
vector < int > v, v1;
bool used[1001][1001];

int main()
{
    cin >> n >> k;
    cin >> a >> b >> c >> d;
    if( n == 4 ){
        cout << -1 << endl;
        return 0;
    }
    v.pb(a);
    v.pb(c);
    for( i = 1; i <= n; i++ ){
        if( i == a || i == b || i == c || i == d )
            continue;
        v.pb(i);
    }
    v.pb(d);
    v.pb(b);
    v1 = v;
    swap(v1[0], v1[1]);
    swap(v1[v.size() - 1], v1[v.size() - 2]);
    for( i = 0; i < v.size() - 1; i++ ){
        int x = v[i], y = v[i + 1];
        if( !used[x][y] ){
            used[x][y] = used[y][x] = true;
            cnt++;
        }
    }
    for( i = 0; i < v1.size() - 1; i++ ){
        int x = v1[i], y = v1[i + 1];
        if( !used[x][y] ){
            used[x][y] = used[y][x] = true;
            cnt++;
        }
    }
    if( cnt > k ){
        cout << -1 << endl;
        return 0;
    }
    for( i = 0; i < v.size(); i++ )
        cout << v[i] << " ";
    cout << endl;
    for( i = 0; i < v1.size(); i++ )
        cout << v1[i] << " ";
}