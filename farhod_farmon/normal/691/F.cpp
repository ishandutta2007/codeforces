#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

const int N = 1000001;

using namespace std;

lli n, c[3 * N], s[3 * N], m;

int main()
{
    //freopen( "photo.in", "r", stdin );
    //freopen( "photo.out", "w", stdout );
    //fin
    //fout
    //ios_base::sync_with_stdio(0);
    sc("%I64d", &n);
    //cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        sc("%I64d", &x);
        //cin >> x;
        c[x]++;
    }
    for(int i = 1; i < 3 * N; i++){
        for(int j = 1; j * i < 3 * N; j++){
            if(i == j)
                s[i * j] += c[i] * (c[i] - 1);
            else
                s[i * j] += c[i] * c[j];
        }
    }
    for(int i = 1; i < 3 * N; i++)
        s[i] += s[i - 1];
    lli total = n * (n - 1);
    sc("%I64d", &m);
    //cin >> m;
    for(int i = 1; i <= m; i++){
        int x;
        sc("%I64d", &x);
        //cin >> x;
        pr("%I64d\n", total - s[x - 1]);
        //cout << total - s[x - 1] << endl;
    }
}