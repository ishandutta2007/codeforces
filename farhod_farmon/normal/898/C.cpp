#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 505;
const long long Q = 1000010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

bool suf(string x, string y)
{
        if(x.size() > y.size()){
                return false;
        }
        for(int i = 0; i < x.size(); i++){
                int j = y.size() - (x.size() - i);
                if(x[i] != y[j]){
                        return false;
                }
        }
        return true;
}

int n;
map < string, vector < string > > d;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int k;
                string x;
                cin >> x >> k;
                for(int j = 1; j <= k; j++){
                        string y;
                        cin >> y;
                        bool can = true;
                        for(auto yy: d[x]){
                                if(yy == y){
                                        can = false;
                                        break;
                                }
                        }
                        if(can){
                                d[x].push_back(y);
                        }
                }
        }
        vector < pair < string, vector < string > > > v;
        for(auto p: d){
                vector < string > g = p.se, gg;
                for(int i = 0; i < g.size(); i++){
                        bool can = true;
                        for(int j = 0; j < g.size(); j++){
                                if(i != j && suf(g[i], g[j])){
                                        can = false;
                                        break;
                                }
                        }
                        if(can){
                                gg.push_back(g[i]);
                        }
                }
                v.push_back({p.fi, gg});
        }
        cout << v.size() << "\n";
        for(auto p: v){
                cout << p.fi << " " << p.se.size() << " ";
                for(auto x: p.se){
                        cout << x << " ";
                }
                cout << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}