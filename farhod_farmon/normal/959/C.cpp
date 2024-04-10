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

void solve()
{
        cin >> n;
        if(n < 6){
                cout << -1 << "\n";
        }
        else{
                for(int i = 1; i <= n / 2; i++){
                        cout << 1 << " " << i + 1 << "\n";
                }
                for(int i = n / 2 + 1; i < n; i++){
                        cout << 2 << " " << i + 1 << "\n";
                }
        }
        for(int i = 1; i < n; i++){
                cout << i << " " << i + 1 << "\n";
        }
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