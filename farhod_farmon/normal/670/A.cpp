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

int n, mx, mn = 1e9;
int d[7] = {0, 0, 0, 0, 0, 1, 1};

int get()
{
    int cnt = 0;
    int g = 0;
    while( g < n ){
        cnt += d[g % 7];
        g++;
    }
    return cnt;
}

int main()
{
    cin >> n;
    for( int i = 1; i <= 7; i++ ){
        int g = get();
        for( int j = 0; j < 6; j++ )
            swap(d[j], d[j + 1]);
        mx = max(mx, g);
        mn = min(mn, g);
    }
    cout << mn << " " << mx << endl;
}