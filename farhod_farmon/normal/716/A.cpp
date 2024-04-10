#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int n, c, a[100100];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> c;
    int cnt = 0;
    a[0] = -1e9;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] - a[i - 1] > c)
            cnt = 1;
        else
            cnt++;
    }
    cout << cnt << endl;
}