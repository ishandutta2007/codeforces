#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;

void solve()
{
        set < pair < int, int > > a, b;
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a.insert({x, i});
        }
        for(int i = 1; i <= n + n; i++){
                char c;
                cin >> c;
                if(c == '0'){
                        auto p = *a.begin();
                        a.erase(a.begin());
                        cout << p.se << " ";
                        b.insert(p);
                }
                else{
                        auto p = *(--b.end());
                        b.erase(--b.end());
                        cout << p.se << " ";
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}