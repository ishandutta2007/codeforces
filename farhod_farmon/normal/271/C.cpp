#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 2000000;
const int MX = 300100;

using namespace std;

int n, k;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    if(k * 3 > n){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i <= k; i++)
        cout << i << " " << i << " ";
    for(int i = 1; i <= k; i++)
        cout << i << " ";
    for(int i = 1; i <= n - 3 * k; i++)
        cout << 1 << " ";
    return 0;
}