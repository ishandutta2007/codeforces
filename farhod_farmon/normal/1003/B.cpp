#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int a, b, x;

void solve()
{
        vector < pair < int, int > > v;
        cin >> a >> b >> x;
        int g = 0;
        if(b > a){
                g = 1;
        }
        for(int i = 1; i <= x + 1; i++){
                v.push_back({g, 1});
                if(g)b--;
                else a--;
                g = 1 - g;
        }
        for(int i = 0; i < v.size(); i++){
                if(v[i].fi == 0){
                        v[i].se += a; a = 0;
                }
                else{
                        v[i].se += b; b = 0;
                }
                for(int j = 0; j < v[i].se; j++){
                        cout << v[i].fi;
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