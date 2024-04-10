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

const int N = 500500;

using namespace std;

int ans, cnt, x, p, n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    p = 1e9;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(x > p)
            cnt++;
        else
            cnt = 1;
        p = x;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}