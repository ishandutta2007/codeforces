#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
int g;
int d[N][26];
bool used[N];
set < pair < int, int > > s[N];

void dfs(int x, int l)
{
        for(int i = 0; i < 26; i++){
                int y = d[x][i];
                if(y == 0){
                        continue;
                }
                dfs(y, l + 1);
                for(auto p: s[y]){
                        s[x].insert(p);
                }
        }
        if(used[x]){
                s[x].insert({l, x});
        }
        else{
                if(!s[x].empty()){
                        s[x].erase(--s[x].end());
                        s[x].insert({l, x});
                }
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x = 0;
                string s;
                cin >> s;
                for(int j = 0; j < s.size(); j++){
                        if(!d[x][s[j] - 'a']){
                                d[x][s[j] - 'a'] = ++g;
                        }
                        x = d[x][s[j] - 'a'];
                }
                used[x] = 1;
        }
        used[0] = 1;
        dfs(0, 0);
        int ans = 0;
        for(auto p: s[0]){
                ans += p.fi;
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