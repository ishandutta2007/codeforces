#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 100001;

using namespace std;

vector < string > v[200];
int n, i, q;

int rec( string s )
{
    if( s.size() == n )return 1;
    char c = s[0];
    string t = "";
    for( int j = 1; j < s.size(); j++ )t += s[j];
    int cnt = 0;
    for( int j = 0; j < v[c].size(); j++ )cnt += rec(v[c][j] + t);
    return cnt;
}

int main()
{
    char y;
    string x;
    cin >> n >> q;
    for( i = 1; i <= q; i++ ){
        cin >> x >> y;
        v[y].pb(x);
    }
    cout << rec("a") << endl;
}