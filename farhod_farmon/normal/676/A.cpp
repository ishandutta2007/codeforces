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

int n, x[101], i, j, h, mx;

int main()
{
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> x[i];
    for(i = 1; i <= n; i++){
        for(j = i + 1; j <= n; j++){
            swap(x[i], x[j]);
            int i1, in;
            for(h = 1; h <= n; h++){
                if(x[h] == 1)
                    i1 = h;
                if(x[h] == n)
                    in = h;
            }
            mx = max(mx, abs(in - i1));
            swap(x[i], x[j]);
        }
    }
    cout << mx << endl;
}