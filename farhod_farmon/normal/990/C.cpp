#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int f[N];
int s[N];
int g[N + N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                string t;
                cin >> t;
                for(int j = 0; j < t.size(); j++){
                        if(t[j] == '('){
                                f[i]++;
                        }
                        else{
                                f[i]--;
                        }
                        s[i] = max(s[i], -f[i]);
                }
                if(s[i] == 0){
                        g[f[i] + N]++;
                }
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
                if(-f[i] >= s[i]){
                        ans += g[-f[i] + N];
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