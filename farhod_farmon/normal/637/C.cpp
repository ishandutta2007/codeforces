#include <bits/stdc++.h>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second

const int N = 1111;

using namespace std;

int n;
int ans = 6;
string p[N];

int f( string s, string t )
{
    int kol = 0;
    for( int i = 0; i < s.size(); i++ ){
        if( s[i] != t[i] )kol++;
    }
    return kol;
}

int main()
{
    cin >> n;
    for( int i = 1; i <= n; i++ )cin >> p[i];
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= n; j++ ){
            if( i == j )continue;
            int g = f(p[i], p[j]);
            ans = min(ans, (g + 1) / 2 - 1);
        }
    }
    cout << ans << endl;
}