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

int n, m;
bool ans = true;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if(c == 'C' || c == 'M' || c == 'Y')
                ans = false;
        }
    }
    if(ans)
        cout << "#Black&White" << endl;
    else
        cout << "#Color" << endl;
}