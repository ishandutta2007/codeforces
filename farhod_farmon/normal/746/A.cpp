#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

int a, b, c;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> a >> b >> c;
    int ans = 0;
    for(int i = 1; i <= 1000; i++){
        if(i <= a && 2 * i <= b && 4 * i <= c)
            ans = max(ans, 7 * i);
    }
    cout << ans << endl;
}