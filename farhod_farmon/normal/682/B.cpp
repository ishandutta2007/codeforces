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

int n, a[100001], cnt, x;

int main()
{
    //fin
    //fout
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    x = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] < x)
            continue;
        x = x + 1;
    }
    cout << x << endl;
}