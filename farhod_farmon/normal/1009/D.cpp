#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int m;

void solve()
{
        cin >> n >> m;
        if(m < n - 1){
                cout << "Impossible" << "\n";
                return;
        }
        vector < pair < int, int > > v;
        for(int i = 1; i < n; i++){
                for(int j = 1; j + i <= n && m; j++){
                        if(__gcd(j, j + i) == 1){
                                v.push_back({j, j + i});
                                m--;
                        }
                }
        }
        if(m){
                cout << "Impossible" << "\n";
                return;
        }
        cout << "Possible" << "\n";
        for(auto p: v){
                cout << p.fi << " " << p.se << "\n";
        }
}

bool mtest = false; int main()
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