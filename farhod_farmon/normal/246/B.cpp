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
    int n, s = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s += x;
    }
    s = (s % n + n) % n;
    if(s == 0)
        cout << n << endl;
    else
        cout << n - 1 << endl;
}