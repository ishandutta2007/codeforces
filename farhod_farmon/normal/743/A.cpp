#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 400400;

using namespace std;

string s;
int n, x, y;
int l[N][2];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> x >> y >> s;
    int ans = 1e9;
    l[0][0] = l[0][1] = -1e9;
    for(int i = 0; i < n; i++){
        s[i] -= '0';
        l[i][s[i]] = i;
        ans = min(ans, l[i][s[i]] - l[i][1 ^ s[i]]);
        l[i + 1][0] = l[i][0];
        l[i + 1][1] = l[i][1];
    }
    if(s[x - 1] == s[y - 1] || x == y)
        ans = 0;
    cout << ans << endl;
}