#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int d;
int s[N];

void solve()
{
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                s[x]++;
        }
        for(int i = 1; i < N; i++){
                s[i] += s[i - 1];
        }
        int ans = 1e9;
        for(int i = 1; i + d < N; i++){
                ans = min(ans, s[i - 1] + s[N - 1] - s[i + d]);
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