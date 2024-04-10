#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200100;

using namespace std;

int ans = 1e9;
int n, a[101];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 2; i <= n - 1; i++){
        int mx = 0;
        for(int j = 2; j <= n; j++){
            if(j == i)
                continue;
            if(j - 1 == i)
                mx = max(mx, a[j] - a[j - 2]);
            else
                mx = max(mx, a[j] - a[j - 1]);
        }
        ans = min(ans, mx);
    }
    cout << ans << endl;
}