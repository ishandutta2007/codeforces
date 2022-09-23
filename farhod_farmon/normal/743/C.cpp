#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 400400;

using namespace std;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if(n == 1)
        cout << -1 << endl;
    else
        cout << n << " " << n + 1 << " " << n * (n + 1) << endl;
}