#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 111;
const long long mod = 1e9 + 7;

using namespace std;

long long n, k, G;
long long f1, f2;

void solve(long long a, long long b)
{
        b -= a;
        for(int i = 1; i <= n; i++){
                long long l = b;
                l %= G;
                if(l < 0){
                        l += G;
                }
                b += k;
                f1 = max(f1, __gcd(G, l));
                f2 = min(f2, __gcd(G, l));
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        long long a, b;
        cin >> n >> k >> a >> b;
        G = n * k;
        f2 = 1e10;
        for(long long x: {a, k - a}){
                for(long long y: {b, k - b}){
                        solve(x, y);
                }
        }
        cout << G / f1 << " " << G / f2 << "\n";
}