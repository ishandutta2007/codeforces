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

int n, m;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int ans = 1e9 + 1;
    for(int i = 1; i <= m; i++){
        int l, r;
        cin >> l >> r;
        ans = min(ans, r - l + 1);
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++)
        cout << i % ans << " ";
}