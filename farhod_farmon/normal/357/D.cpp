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

lli n, m, i, d[1000001][30], cnt;
string s, t;

int main()
{
    cin >> n >> m;
    cin >> s >> t;
    lli a = s.size();
    lli b = t.size();
    lli g = __gcd(a, b);
    lli l = a * b / g;
    cnt = l;
    for( i = 0; i < a; i++ ){
        d[i % g][s[i] - 'a']++;
    }
    for( i = 0; i < b; i++ )
        cnt -= d[i % g][t[i] - 'a'];
    cout << cnt * (n * a / l) << endl;
}