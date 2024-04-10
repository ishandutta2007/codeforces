#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
string s, t;
vector < int > v;

void solve()
{
        cin >> n >> m;
        cin >> s >> t;
        for(int i = 0; i < s.size(); i++){
                v.pb(i);
        }
        for(int i = 0; i + s.size() <= t.size(); i++){
                vector < int > g;
                for(int j = 0; j < s.size(); j++){
                        if(t[i + j] != s[j]){
                                g.pb(j);
                        }
                }
                if(g.size() < v.size()) v = g;
        }
        cout << v.size() << endl;
        for(int x: v){
                cout << x + 1 << " ";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}