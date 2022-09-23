#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000100;
const long long MX = 11;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

string s;
int pw[N];

void solve()
{
        cin >> s;
        pw[0] = 1;
        for(int i = 1; i < N; i++){
                pw[i] = (pw[i - 1] + pw[i - 1]) % mod;
        }
        for(int i = 0; i < N; i++){
                pw[i] = (pw[i] - 1 + mod) % mod;
        }
        int ans = 0, l = 0;
        for(int i = 0; i < s.size(); i++){
                if(s[i] == 'a'){
                        l++;
                }
                else{
                        ans = (ans + pw[l]) % mod;
                }
        }
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}