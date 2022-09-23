#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int a[8];

void solve()
{
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
                for(int j = 0; j < 7; j++){
                        char c;
                        cin >> c;
                        a[j] += c - '0';
                }
        }
        int ans = 0;
        for(int i = 0; i < 7; i++){
                ans = max(ans, a[i]);
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}