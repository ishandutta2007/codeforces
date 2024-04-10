#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long Q = 2e18;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
string s;
string a[N];

void solve()
{
        string t = "";
        cin >> s >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        t += a[i];
                        t += a[j];
                }
        }
        for(int i = 0; i + 1 < t.size(); i++){
                if(t[i] == s[0] && t[i + 1] == s[1]){
                        cout << "YES" << "\n";
                        return;
                }
        }
        cout << "NO" << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}