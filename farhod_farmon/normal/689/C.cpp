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

lli kol(lli m)
{
    lli cnt = 0;
    lli x = 2;
    while(x * x * x <= m){
        cnt += m / (x * x * x);
        x++;
    }
    return cnt;
}

int main()
{
    //freopen( "angry.in", "r", stdin );
    //freopen( "angry.out", "w", stdout );
    //fin
    //fout
    lli k;
    cin >> k;
    lli l = 8, r = 4e18;
    while(l < r){
        lli m = (l + r) / 2ll;
        if(kol(m) < k)
            l = m + 1;
        else
            r = m;
    }
    if(kol(l) == k)
        cout << l << endl;
    else
        cout << -1 << endl;
}