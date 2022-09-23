#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;

void solve()
{
        vector < pair < int, int > > v;
        cin >> n;
        for(int i = 1; i <= n; i++){
                int l, r;
                cin >> l >> r;
                v.push_back({l, 1});
                v.push_back({r + 1, -1});
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        for(auto p: v){
                cnt += p.se;
                if(cnt > 2){
                        cout << "NO" << "\n";
                        return;
                }
        }
        cout << "YES" << "\n";
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