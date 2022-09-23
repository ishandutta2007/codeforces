#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

lli n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n;
    if(n <= 2)
        cout << -1 << endl;
    else if(n % 2)
        cout << n * n / 2 << " " << n * n / 2 + 1 << endl;
    else
        cout << (n / 2) * (n / 2) - 1 << " " << (n / 2) * (n / 2) + 1 << endl;
}