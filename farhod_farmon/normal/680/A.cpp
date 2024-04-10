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

int t[10], ans = 1e9, cnt;

int main()
{
    for(int i = 0; i < 5; i++)
        cin >> t[i],
        cnt += t[i];
    sort(t, t + 5);
    for(int i = 0; i < 5; i++)
        if(t[i] == t[i + 1])
            if(t[i] == t[i + 2])
                ans = min(ans, cnt - t[i] * 3);
            else
                ans = min(ans, cnt - t[i] * 2);
    cout << min(ans, cnt) << endl;
}