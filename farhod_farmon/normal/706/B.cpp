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

int n, q, d[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        d[x]++;
    }
    for(int i = 1; i < N; i++)
        d[i] += d[i - 1];
    cin >> q;
    for(int i = 1; i <= q; i++){
        int x;
        cin >> x;
        cout << d[min(x, N - 1)] << endl;
    }
}