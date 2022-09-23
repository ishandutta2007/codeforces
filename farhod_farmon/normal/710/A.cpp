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

using namespace std;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    string s;
    cin >> s;
    int x = s[0] - 'a' + 1,
        y = s[1] - '0';
    int ans = 0;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            if(x + i >= 1 && x + i <= 8 && y + j >= 1 && y + j <= 8)
                ans++;
    cout << ans - 1 << endl;
}