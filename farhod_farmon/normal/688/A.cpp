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

const int N = 755;

using namespace std;

int n, d, cnt, ans;
char c[101][101];

int main()
{
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> n >> d;
    for(int i = 1; i <= d; i++){
        bool b = true;
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            if(c[i][j] == '0')
                b = false;
        }
        if(!b)
            cnt++;
        else
            cnt = 0;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}