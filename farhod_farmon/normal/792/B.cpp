#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];
bool used[N];
vector < int > v;

void solve()
{
        cin >> n >> k;
        for(int i = 0; i < n; i++)
        {
                used[i] = true;
        }
        int x = 0;
        for(int i = 1; i <= k; i++)
        {
                cin >> a[i];
                a[i] %= (n - i + 1);
                if(a[i])x = (x + 1) % n;
                while(a[i])
                {
                        if(used[x])
                        {
                                a[i]--;
                        }
                        if(a[i])
                        {
                                x = (x + 1) % n;
                        }
                }
                cout << x + 1 << " ";
                used[x] = false;
                x = (x + 1) % n;
                while(used[x] == false)
                {
                        x = (x + 1) % n;
                }
        }
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