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

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string ans = "NO";
    while(n--){
        string s;
        int x, y;
        cin >> s >> x >> y;
        if(x >= 2400 && y - x > 0)
            ans = "YES";
    }
    cout << ans << endl;
}