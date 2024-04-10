#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 300300;

using namespace std;

int n, a[N];
lli l[N], r[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    sc("%d", &n);
    for(int i = 1; i <= n; i++)
        sc("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 2; i <= n; i++)
        l[i] = l[i - 1] + 1ll * (a[i] - a[i - 1]) * (i - 1);
    for(int i = n - 1; i >= 1; i--)
        r[i] = r[i + 1] + 1ll * (a[i + 1] - a[i]) * (n - i);
    lli sum = 1e18;
    int ans = -1;
    for(int i = 1; i <= n; i++){
        if(l[i] + r[i] < sum){
            sum = l[i] + r[i];
            ans = a[i];
        }
    }
    cout << ans << endl;
}