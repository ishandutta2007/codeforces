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

bool can(int x, int g)
{
    for(int i = 1; i <= n; i++){
        if(abs(a[i] - x) == g)
            continue;
        if(a[i] == x)
            continue;
        return false;
    }
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int mn = 1e9, mx = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    if(can(mn, mx - mn) || can(mx, mx - mn) || ((mx - mx) % 2 == 0 && can(mn + (mx - mn) / 2, (mx - mn) / 2)))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}