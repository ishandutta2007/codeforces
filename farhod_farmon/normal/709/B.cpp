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

int n, a[N];

int f(int x, int y, int z)
{
    return abs(x - y) + min(abs(x - z), abs(y - z));
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int x;
    cin >> n >> x;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    cout << min(f(a[1], a[n - 1], x), f(a[2], a[n], x)) << endl;
}