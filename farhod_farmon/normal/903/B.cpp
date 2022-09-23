#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 1000010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int h1, a1, h2, a2, c;

void solve()
{
        vector < string > v;
        cin >> h1 >> a1 >> c >> h2 >> a2;
        while(true){
                if(h2 - a1 <= 0){
                        v.push_back("STRIKE");
                        break;
                }
                if(h1 - a2 <= 0){
                        v.push_back("HEAL");
                        h1 += c;
                }
                else{
                        v.push_back("STRIKE");
                        h2 -= a1;
                }
                h1 -= a2;
        }
        cout << v.size() << "\n";
        for(auto x: v){
                cout << x << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("game.in");
        //fout("game.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}