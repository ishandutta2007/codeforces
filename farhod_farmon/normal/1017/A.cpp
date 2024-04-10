#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
vector < pair < int, int > > v;


void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                v.push_back({- a - b - c - d, i});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
                if(v[i].se == 1){
                        cout << i + 1 << "\n";
                }
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