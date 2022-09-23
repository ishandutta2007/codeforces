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

int n, d[101], a, cnt;

int main()
{
    cin >> n >> a;
    for(int i = 1; i <= n; i++)
        cin >> d[i];
    for(int i = 0; i < n; i++){
        bool b1 = false, b2 = false;
        int c1 = 0, c2 = 0;
        if(a - i < 1)
            b1 = true;
        else if(d[a - i])
            c1 = 1;
        if(a + i > n)
            b2 = true;
        else if(d[a + i])
            c2 = 1;
        if((b1 || c1) && (b2 || c2))
            cnt += c1 + c2;
    }
    cout << cnt - d[a] << endl;
}