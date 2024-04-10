#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1001000;

using namespace std;

long long n, d[N];
long long mod = 1e9 + 7;

void add(long long x, long long y)
{
    while(x < N){
        d[x] = (d[x] + y) % mod;
        x += (x & -x);
    }
}

long long get(long long x)
{
    long long cnt = 0;
    while(x > 0){
        cnt = (cnt + d[x]) % mod;
        x -= (x & -x);
    }
    return cnt;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(long long i = 1; i <= n; i++){
        long long x;
        cin >> x;
        long long g = get(x);
        long long x1 = get(x - 1);
        long long nw = (g * x + x) % mod;
        g = g - x1;
        nw = (nw - g + mod) % mod;
        add(x, nw);
    }
    cout << get(N - 1) << endl;
}