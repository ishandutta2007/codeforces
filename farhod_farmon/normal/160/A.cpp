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

int n, a[101];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        a[i] = a[i - 1] + a[i];
    for(int i = n; i >= 1; i--){
        if(a[n] - a[i - 1] > a[i - 1]){
            cout << n - i + 1 << endl;
            return 0;
        }
    }
}