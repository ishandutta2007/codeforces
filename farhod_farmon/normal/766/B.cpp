#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll a[N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 3; i <= n; i++){
        if(a[i] < a[i - 1] + a[i - 2]){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t = 1;
    if(mtest)
        cin >> t;
    while(t--)
        solve();
}