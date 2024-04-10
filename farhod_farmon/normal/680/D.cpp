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

pair < lli, lli > p;

lli pw(lli x)
{
    return x * x * x;
}

void rec(lli m, lli x, lli y)
{
    if(!m){
        p = max(p, {x, y});
        return;
    }
    lli a = 1;
    while(pw(a + 1) <= m)
        a++;
    rec(m - pw(a), x + 1, y + pw(a));
    if(a > 1)
        rec(pw(a) - pw(a - 1) - 1, x + 1, y + pw(a - 1));
}

int main()
{
    lli m;
    cin >> m;
    rec(m, 0, 0);
    cout << p.fi << " " << p.se << endl;
}