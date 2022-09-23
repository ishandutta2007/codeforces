#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 110;

using namespace std;

int n, k, d[N][N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        d[i % k][x]++;
    }
    int ans = 0;
    for(int i = 0; i < k; i++)
        ans += min(d[i][1], d[i][2]);
    cout << ans << endl;
}