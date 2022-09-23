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

int t[55], p[55], s1, s2, i, n, c;

int main()
{
    cin >> n >> c;
    for( i = 1; i <= n; i++ )
        cin >> p[i];
    for( i = 1; i <= n; i++ )
        cin >> t[i];
    int time = 0;
    for( i = 1; i <= n; i++ ){
        time += t[i];
        s1 += max(0, p[i] - time * c);
    }
    time = 0;
    for( i = n; i >= 1; i-- ){
        time += t[i];
        s2 += max(0, p[i] - time * c);
    }
    if( s1 > s2 )
        cout << "Limak" << endl;
    else if( s1 < s2 )
        cout << "Radewoosh" << endl;
    else
        cout << "Tie" << endl;
}