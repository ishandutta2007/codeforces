#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int n, a, b, c;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n >> a >> b >> c;
    int ans = 0;
    for(int i = 0; i <= n / a; i++){
        for(int j = 0; j <= n / b; j++){
            int h = (n - i * a - j * b) / c;
            if(h < 0)
                continue;
            if(i * a + j * b + h * c == n)
                ans = max(ans, i + j + h);
        }
    }
    cout << ans << endl;
}