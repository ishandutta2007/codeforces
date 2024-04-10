#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 250500;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

string s;

bool can(int l, int r)
{
        int g = (r - l + 1) / 2;
        for(int i = 0; i < g; i++){
                if(s[l + i] != s[r - i]){
                        return true;
                }
        }
        return false;
}

void solve()
{
        cin >> s;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
                for(int j = i; j < s.size(); j++){
                        if(can(i, j)){
                                ans = max(ans, j - i + 1);
                        }
                }
        }
        cout << ans << "\n";
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