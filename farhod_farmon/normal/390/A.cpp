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

int d1[111], d2[111];
int n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        d1[x] = 1;
        d2[y] = 1;
    }
    int x = 0, y = 0;
    for(int i = 0; i <= 100; i++){
        x += d1[i];
        y += d2[i];
    }
    cout << min(x, y) << endl;
}