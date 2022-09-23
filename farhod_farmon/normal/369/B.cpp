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

using namespace std;

int n, a[1011], k, l, r, S, s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    cin >> n >> k >> l >> r >> S >> s;
    for(int i = 1; i <= n; i++)
        a[i] = l;
    S -= n * l;
    s -= k * l;
    while(s){
        for(int i = 1; i <= k && s; i++, s--, S--)
            a[i]++;
    }
    while(S){
        for(int i = k + 1; i <= n && S; i++, S--)
            a[i]++;
    }
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
}