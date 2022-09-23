#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 500500;
const long long Q = 2002 * 50;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
char c[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        bool good = true;
        for(int i = 1; i <= n / 2; i++){
                int g = abs(c[i] - c[n - i + 1]);
                if(g != 0 && g != 2){
                        good = false;
                }
        }
        if(good){
                cout << "YES" << "\n";
        }
        else{
                cout << "NO" << "\n";
        }
}

bool mtest = true; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}