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

lli n, k, x, g = 1;
bool b = false;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> x;
        g = g * x / __gcd(g, x);
        g = __gcd(g, k);
    }
    if(g == k)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}