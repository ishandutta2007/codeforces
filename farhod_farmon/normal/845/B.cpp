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

string t;

int dif(string x, string y)
{
        int cnt = 0;
        for(int i = 0; i < x.size(); i++){
                cnt += (x[i] != y[i]);
        }
        return cnt;
}

string f(int x)
{
        string s = "";
        for(int i = 0; i < 6; i++){
                s += char(x % 10 + '0');
                x /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
}

void solve()
{
        cin >> t;
        int ans = 1e9;
        for(int i = 0; i < 1000000; i++){
                string s = f(i);
                int f1 = s[0] + s[1] + s[2], f2 = s[3] + s[4] + s[5];
                if(f1 == f2){
                        ans = min(ans, dif(t, s));
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