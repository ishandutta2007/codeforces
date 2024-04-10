#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
char c[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        int ans = n;
        for(int i = 1; i + i <= n; i++){
                bool can = true;
                for(int j = 1; j <= i; j++){
                        if(c[j] != c[i + j]){
                                can = false;
                        }
                }
                if(can){
                        ans = min(ans, 1 + i + n - (i + i));
                }
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