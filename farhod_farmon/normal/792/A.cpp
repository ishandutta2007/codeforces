#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int ans = 2e9 + 2;
        int cnt = 0;
        for(int i = 2; i <= n; i++)
        {
                int l = a[i] - a[i - 1];
                if(l < ans)
                {
                        ans = l;
                        cnt = 1;
                }
                else if(l == ans)
                {
                        cnt++;
                }
        }
        cout << ans << " " << cnt << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("friendcross.in");
        //fout("friendcross.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}