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

int n, k, i;

int main()
{
    cin >> n >> k;
    cout << (n * 6 - 1) * k << "\n";
    for( i = 0; i < n; i++ ){
        cout << (i * 6 + 1) * k << " ";
        cout << (i * 6 + 2) * k << " ";
        cout << (i * 6 + 3) * k << " ";
        cout << (i * 6 + 5) * k << "\n";
    }
}