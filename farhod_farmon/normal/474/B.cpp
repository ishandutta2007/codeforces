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

int n, m, d[N * 10];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int s = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for(int j = s + 1; j <= s + x; j++)
            d[j] = i;
        s += x;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        cout << d[x] << endl;
    }
}