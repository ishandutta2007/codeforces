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

lli cnt, a, cnt1;
map < int, bool > used;

void rec( lli b, lli x, lli y )
{
    if( b > a )
        return;
    if( !used[b] )
        cnt++;
    used[b] = true;
    rec(b * 10 + x, x, y);
    rec(b * 10 + y, x, y);
}

int main()
{
    cin >> a;
    for( lli i = 1; i < 10; i++ ){
        for( lli j = i; j < 10; j++ ){
            rec(i * 10 + j, i, j);
            rec(j * 10 + i, i, j);
            rec(i * 10 + i, i, j);
            rec(j * 10 + j, i, j);
            rec(i, i, 0);
        }
    }
    cout << cnt - cnt1 << endl;
}