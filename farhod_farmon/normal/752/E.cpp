#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;
const int MX = 20010000;

using namespace std;

long long n;
long long k;
long long d[MX];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%I64d%I64d", &n, &k);
    for(int i = 1; i <= n; i++){
        int x;
        sc("%d", &x);
        d[x]++;
    }
    long long all = 0;
    for(int i = MX / 2 - 10; i >= 1; i--){
        d[i] += d[i * 2] + d[i * 2];
        d[i - 1] += d[i * 2 - 1];
        if(i > 1){
            d[i] += d[i * 2 - 1];
            all -= d[i * 2 - 1];
        }
        all += d[i] - d[i * 2];
        if(all >= k){
            pr("%d", i);
            return 0;
        }
    }
    pr("-1");
    return 0;
}