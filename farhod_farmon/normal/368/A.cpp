#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 110;

using namespace std;

int n, d, m, a[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    sort(a + 1, a + n + 1);
    for(int i = n + 1; i <= 100; i++)
        a[i] = -d;
    int cnt = 0;
    for(int i = 1; i <= m; i++)
        cnt += a[i];
    cout << cnt << endl;
}