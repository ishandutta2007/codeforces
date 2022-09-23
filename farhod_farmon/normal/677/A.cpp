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

int n, h, x, cnt;

int main()
{
    cin >> n >> h;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(x > h)
            cnt += 2;
        else
            cnt += 1;
    }
    cout << cnt << endl;
}