#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int cnt;
bool used[200];

void solve()
{
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                if('A' <= c && c <= 'Z'){
                        for(int j = 'a'; j <= 'z'; j++){
                                used[j] = 0;
                        }
                        cnt = 0;
                        continue;
                }
                cnt += 1 - used[c];
                used[c] = 1;
                ans = max(ans, cnt);
        }
        cout << ans << "\n";
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}