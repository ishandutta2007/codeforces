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

string s;
int f[N][3];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        f[i + 1][s[i] - 'x']++;
        f[i + 1][0] += f[i][0];
        f[i + 1][1] += f[i][1];
        f[i + 1][2] += f[i][2];
    }
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int l, r;
        cin >> l >> r;
        int mn = f[r][0] - f[l - 1][0],
            mx = f[r][0] - f[l - 1][0];
        mn = min(mn, f[r][1] - f[l - 1][1]);
        mn = min(mn, f[r][2] - f[l - 1][2]);
        mx = max(mx, f[r][1] - f[l - 1][1]);
        mx = max(mx, f[r][2] - f[l - 1][2]);
        if(r - l + 1 >= 3 && abs(mn - mx) > 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}