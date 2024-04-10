#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100020;

using namespace std;

long long n, m;
long long q[N], w[N];

long long f(long long x)
{
    if(x % 2)
        return x * (x - 1) / 2;
    else
        return x * (x - 1) / 2 + x / 2 - 1;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> q[i] >> w[i];
    sort(w + 1, w + m + 1);
    long long l = 1,
              r = m;
    while(l < r){
        long long mid = (l + r) / 2;
        if(f(mid + 1) + 1 <= n)
            l = mid + 1;
        else
            r = mid;
    }
    long long ans = 0;
    for(int i = 1; i <= l; i++)
        ans += w[m - i + 1];
    cout << ans << endl;
}