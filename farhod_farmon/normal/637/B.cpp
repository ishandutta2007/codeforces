#include <bits/stdc++.h>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

map < string, bool > m;
string s[200002];
int i, n;

int main()
{
    cin >> n;
    for( i = 1; i <= n; i++ )cin >> s[i];
    for( i = n; i >= 1; i-- ){
        if( m[s[i]] )continue;
        cout << s[i] << endl;
        m[s[i]] = true;
    }
}