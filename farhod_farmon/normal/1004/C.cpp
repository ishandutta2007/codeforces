#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
int s[N];
bool used[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                s[i] = s[i - 1] + 1 - used[a[i]];
                used[a[i]] = 1;
        }
        for(int i = 1; i < N; i++){
                used[i] = 0;
        }
        long long ans = 0;
        for(int i = n; i >= 1; i--){
                if(!used[a[i]]){
                        ans += s[i - 1];
                }
                used[a[i]] = 1;
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