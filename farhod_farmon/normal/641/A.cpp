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

lli n, i, j, h, d[100001];
string s;
bool used[100001];

int main()
{
    cin >> n;
    cin >> s;
    for( i = 0; i < n; i++ )
        cin >> d[i];
    lli x = 0;
    while( x >= 0 && x < n ){
        if( used[x] ){
            cout << "INFINITE" << endl;
            return 0;
        }
        used[x] = true;
        if( s[x] == '>' )
            x += d[x];
        else
            x -= d[x];
    }
    cout << "FINITE" << endl;
}