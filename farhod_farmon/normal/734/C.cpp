#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

long long n, m, k;
long long x, s;
long long a[N];
long long b[N];
long long c[N];
long long d[N];

long long get(long long cost, long long f)
{
    int l = 0,
        r = k;
    while(l < r){
        int mid = (l + r) / 2;
        if(d[mid + 1] <= cost)
            l = mid + 1;
        else
            r = mid;
    }
    return max(0ll, n - c[l]) * f;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("three.in");
    //fout("three.out");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k >> x >> s;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    for(int i = 1; i <= k; i++)
        cin >> c[i];
    for(int i = 1; i <= k; i++)
        cin >> d[i];
    for(int i = 1; i <= k; i++)
        c[i] = max(c[i], c[i - 1]);
    long long ans = get(s, x);
    for(int i = 1; i <= m; i++)
        if(s >= b[i])
            ans = min(ans, get(s - b[i], a[i]));
    cout << ans << endl;
}