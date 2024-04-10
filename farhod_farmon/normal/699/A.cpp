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

int n, x[200100], ans = 1e9;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
        if(i > 1 && s[i - 2] == 'R' && s[i - 1] == 'L')
            ans = min(ans, (x[i] - x[i - 1]) / 2);
    }
    if(ans == 1e9)
        ans = -1;
    cout << ans << endl;
}