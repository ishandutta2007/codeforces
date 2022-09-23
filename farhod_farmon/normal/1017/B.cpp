#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
char a[N];
char b[N];
int d[2][2];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] -= '0';
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
                b[i] -= '0';
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
                if(a[i] == 0 && b[i] == 0){
                        ans += d[1][0] + d[1][1];
                }
                else if(a[i] == 0 && b[i] == 1){
                        ans += d[1][0];
                }
                else if(a[i] == 1 && b[i] == 0){
                        ans += d[0][0] + d[0][1];
                }
                else{
                        ans += d[0][0];
                }
                d[a[i]][b[i]]++;
        }
        cout << ans << "\n";
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