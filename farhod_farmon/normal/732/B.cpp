#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 505;

using namespace std;

int n, k, a[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(a[i] + a[i + 1] >= k)
            continue;
        cnt += k - a[i] - a[i + 1];
        a[i + 1] += k - a[i] - a[i + 1];
    }
    cout << cnt << endl;
    for(int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
}