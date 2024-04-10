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

const int N = 100100;

using namespace std;

lli n, m, a[N], b[N];

bool can(lli x)
{
    lli j = 1;
    for(lli i = 1; i <= n; i++){
        if(a[i] < b[j] - x)
            return false;
        while(j <= m && a[i] > b[j] + x)
            j++;
        if(j > m || a[i] < b[j] - x || a[i] > b[j] + x)
            return false;
    }
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(lli i = 1; i <= n; i++)
        cin >> a[i];
    for(lli i = 1; i <= m; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    lli l = 0, r = 2e9;
    while(l < r){
        lli m = (l + r) / 2ll;
        if(can(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
}