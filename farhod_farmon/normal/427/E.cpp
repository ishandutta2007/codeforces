#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1000010;

using namespace std;

long long n, k;
long long a[N];

long long f(int x)
{
    long long cnt = 0;
    for(int i = n; i > x; i -= k)
        cnt += a[i] - a[x] + a[i] - a[x];
    for(int i = 1; i < x; i += k)
        cnt += a[x] - a[i] + a[x] - a[i];
    return cnt;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%I64d%I64d", &n, &k);
    for(int i = 1; i <= n; i++)
        sc("%I64d", &a[i]);
    pr("%I64d\n", f(n / 2 + 1));
}