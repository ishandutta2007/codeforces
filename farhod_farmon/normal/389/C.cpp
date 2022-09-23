#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 105;

using namespace std;

int n, a[N];
int d[N];

bool can(int t)
{
    for(int i = 0; i < t; i++)
        d[i] = a[n - i];
    for(int i = n - t, j = 0; i >= 1; i--, j = (j + 1) % t)
        d[j] = min(d[j] - 1, a[i]);
    for(int i = 0; i < t; i++)
        if(d[i] < 0)
            return false;
    return true;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int cur = 0,
        cnt = 0;
    for(int i = 1; i <= n; i++){
        if(can(i)){
            cout << i << endl;
            return 0;
        }
    }
}