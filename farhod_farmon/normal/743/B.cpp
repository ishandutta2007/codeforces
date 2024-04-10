#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 400400;

using namespace std;

long long n, k;

long long solve(long long n, long long k)
{
    long long g = (1ll << n) - 1;
    if(g / 2 + 1 == k)
        return n;
    return solve(n - 1, k % (g / 2 + 1));
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    cout << solve(n, k) << endl;
}