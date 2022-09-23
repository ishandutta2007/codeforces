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

using namespace std;

int n, a[500005], cnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 0, r = n / 2;
    while(l <= r){
        int m = (l + r) / 2;
        bool b = true;
        for(int i = m; i >= 1; i--)
            if(a[i] * 2 > a[n - m + i])
                b = false;
        if(b){
            l = m + 1;
            cnt = n - m;
        }
        else
            r = m - 1;
    }
    cout << cnt << endl;
}