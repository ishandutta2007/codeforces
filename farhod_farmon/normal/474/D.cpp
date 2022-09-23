#include <bits/stdc++.h>

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

int k;
int s[N];
int d[N][2];
int mod = 1e9 + 7;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t >> k;
    d[0][1] = 1;
    for(int i = 1; i < N; i++){
        if(i >= k)
            d[i][0] = (d[i][0] + d[i - k][0] + d[i - k][1]) % mod;
        d[i][1] = (d[i - 1][0] + d[i - 1][1]) % mod;
        s[i] = (s[i - 1] + d[i][0]) % mod;
        s[i] = (s[i] + d[i][1]) % mod;
    }
    for(int i = 1; i <= t; i++){
        int l, r;
        cin >> l >> r;
        cout << (s[r] - s[l - 1] + mod) % mod << endl;
    }
}