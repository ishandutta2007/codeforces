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
const int MAGIC = sqrt(N);
const long long mod = 5e7 + 17;

using namespace std;

int n;
int a[N];
int mx = 0;
int mn = 1e9;

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > mn && a[i] < mx)
            cnt++;
    }
    cout << cnt << endl;
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
}