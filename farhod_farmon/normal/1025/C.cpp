#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 10100;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
int s[N];
string t;

void solve()
{
        cin >> t;
        n = t.size();
        for(int i = 1; i <= n + n; i++){
                if(i <= n){
                        if(t[i - 1] == 'b'){
                                a[i] = 1;
                        }
                }
                else{
                        a[i] = a[i - n];
                }
        }
        int ans = 0;
        for(int i = n + n; i >= 1; i--){
                if(a[i] != a[i + 1]){
                        s[i] = s[i + 1] + 1;
                }
                else{
                        s[i] = 1;
                }
                ans = max(ans, s[i]);
        }
        cout << min(n, ans) << "\n";
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