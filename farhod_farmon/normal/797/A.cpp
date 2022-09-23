#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 400200;
const long long MX = 200200;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
vector < int > v;

void solve()
{
        cin >> n >> k;
        for(int i = 2; i <= n; i++)
        {
                while(n % i == 0)
                {
                        v.pb(i);
                        n /= i;
                }
        }
        if(v.size() < k)
        {
                cout << -1 << endl;
                return;
        }
        while(v.size() > k)
        {
                int x = v.back();
                v.pop_back();
                v[v.size() - 1] *= x;
        }
        for(int x: v)
        {
                cout << x << " ";
        }
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