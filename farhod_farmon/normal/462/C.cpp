#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 300100;

using namespace std;

int n, a[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    long long sum = 0,
              f = 0;
    for(int i = n; i >= 1; i--){
        f += a[i];
        sum += f;
        if(i < n)
            sum += a[i];
    }
    cout << sum << endl;
}