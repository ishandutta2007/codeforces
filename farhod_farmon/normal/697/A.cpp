#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t, s, x;
    cin >> t >> s >> x;
    if((x - t) % s <= 1 && (x - t) / s >= 1 || x == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}