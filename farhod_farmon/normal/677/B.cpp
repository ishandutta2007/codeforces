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

lli n, k, h, x, cnt, cur;

int main()
{
    cin >> n >> h >> k;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(cur + x > h){
            cur = 0;
            cnt++;
        }
        cur += x;
        cnt += cur / k;
        cur %= k;
    }
    if(cur)
        cnt++;
    cout << cnt << endl;
}