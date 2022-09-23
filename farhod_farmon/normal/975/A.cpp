#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
map < string, bool > used;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                string s, t = "";
                cin >> s;
                sort(s.begin(), s.end());
                for(int i = 0; i < s.size(); i++){
                        if(i > 0 && s[i] == s[i - 1]){
                                continue;
                        }
                        t += s[i];
                }
                used[t] = 1;
        }
        cout << used.size() << "\n";
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