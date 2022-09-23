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

int n, a[111];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int s = 10,
        cnt = 0,
        t = 0;
    for(int i = 1; i <= n; i++){
        if(s + a[i] > 720)
            break;
        s += a[i];
        cnt++;
        if(s >= 360)
            t += s - 360;
    }
    cout << cnt << " " << t << endl;
}