#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 15000005;
const long long Q = 10100;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

int n;
int x;
int c[N];
bool used[N];

void solve()
{
        cin >> n;
        int g = 0;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                c[x]++;
                g = __gcd(g, x);
        }
        int ans = 0;
        for(int i = g + 1; i < N; i++){
                int cnt = 0;
                if(used[i]){
                        continue;
                }
                for(int j = i; j < N; j += i){
                        cnt += c[j];
                        used[j] = 1;
                }
                if(cnt > ans){
                        ans = cnt;
                }
        }
        if(ans == 0){
                ans = -1;
        }
        else{
                ans = n - ans;
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}