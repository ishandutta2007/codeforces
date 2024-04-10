#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

char c;
vector < int > v;
int n, k, ans = 1e9;

int get( int i, int j )
{
    int l = i, r = j;
    int m;
    while( l < r ){
        m = (l + r) / 2;
        int x = max(abs(v[m] - v[i]), abs(v[m] - v[j]));
        int y = max(abs(v[m + 1] - v[i]), abs(v[m + 1] - v[j]));
        if( x > y )l = m + 1;
        else r = m;
    }
    int cnt = 1e9;
    for( int h = -1; h <= 1; h++ ){
        if( l + h < i || l + h > j )continue;
        int x = max(abs(v[l + h] - v[i]), abs(v[l + h] - v[j]));
        cnt = min(cnt, x);
    }
    return cnt;
}

int main()
{
    int i, j;
    cin >> n >> k;
    for( i = 1; i <= n; i++ ){
        cin >> c;
        if( c == '0' )v.pb(i);
    }
    for( i = 0; i + k < v.size(); i++ ){
        ans = min(ans, get(i, i + k));
    }
    cout << ans << endl;
}