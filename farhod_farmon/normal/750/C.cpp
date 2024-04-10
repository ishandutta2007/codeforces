#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200100;

using namespace std;

int n;
int c[N];
int d[N];
int ans = 1e9;
int g;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> c[i] >> d[i];
        if(d[i] == 2)
            ans = min(ans, 1899);
        else
            ans = max(ans, 1900);
        if(ans != 1e9)
            ans += c[i];
    }
    g = ans;
    for(int i = n; i >= 1; i--){
        g -= c[i];
        if((g < 1900 ? 2 : 1) != d[i]){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if(ans == 1e9)
        cout << "Infinity" << endl;
    else
        cout << ans << endl;
}