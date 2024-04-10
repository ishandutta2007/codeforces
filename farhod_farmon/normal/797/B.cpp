#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 200200;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
vector < int > v;

void solve()
{
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
                int x;
                cin >> x;
                if(x % 2)
                {
                        v.pb(x);
                }
                else
                {
                        ans += max(0, x);
                }
        }
        sort(v.begin(), v.end());
        ans += v.back();
        for(int i = v.size() - 2; i > 0; i -= 2)
        {
                if(v[i] + v[i - 1] > 0)
                {
                        ans += v[i] + v[i - 1];
                }
                else
                {
                        break;
                }
        }
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("rmq.in");
        //fout("rmq.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}