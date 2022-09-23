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

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    if(n == 1){
        if(k == 0)
            cout << 1 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    int g = n / 2;
    if(g > k){
        cout << -1 << endl;
        return 0;
    }
    k -= g - 1;
    cout << k << " " << k + k << " ";
    for(int i = 1; i <= n - 2; i++)
        cout << (int)(3e8 + i) << " ";
    cout << endl;
}