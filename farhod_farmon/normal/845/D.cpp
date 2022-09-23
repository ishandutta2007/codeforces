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
        cin >> n;
        vector < int > v;
        int ans = 0, o = 0, cur;
        for(int i = 1; i <= n; i++){
                int t, s;
                cin >> t;
                if(t == 1){
                        cin >> s;
                        cur = s;
                }
                else if(t == 2){
                        ans += o;
                        o = 0;
                }
                else if(t == 3){
                        cin >> s;
                        v.push_back(s);
                }
                else if(t == 4){
                        o = 0;
                }
                else if(t == 5){
                        v.clear();
                }
                else if(t == 6){
                        o++;
                }
                while(!v.empty() && v.back() < cur){
                        ans++;
                        v.pop_back();
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