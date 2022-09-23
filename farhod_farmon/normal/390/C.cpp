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

int n, k, w;
int d[N];
char c[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> w;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        c[i] = c[i] - '0';
        d[i] = 1 - c[i];
        for(int j = 1; j < k && i - j > 0; j++)
            d[i] += c[i - j];
        if(i - k > 0)
            d[i] += d[i - k];
    }
    for(int i = 1; i <= w; i++){
        int l, r;
        cin >> l >> r;
        cout << d[r] - d[l - 1] << endl;
    }
}