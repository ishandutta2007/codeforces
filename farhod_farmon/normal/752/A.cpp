#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 300300;

using namespace std;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int n, m, k, a = 1, b = 1;
    cin >> n >> m >> k;
    while(k > 2 * m){
        a++;
        k -= 2 * m;
    }
    while(k > 2){
        b++;
        k -= 2;
    }
    cout << a << " " << b;
    if(k % 2)
        cout << " L";
    else
        cout << " R";
}