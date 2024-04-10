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

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    bool tr = false;
    while(!tr){
        tr = true;
        sort(a + 1, a + n + 1);
        for(int i = n; i > 1; i--){
            if(a[i] > a[i - 1]){
                tr = false;
                a[i] = a[i] - a[i - 1];
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += a[i];
    cout << ans << endl;
}