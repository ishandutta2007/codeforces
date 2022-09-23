#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

int n, a[99];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(a[n] == 15){
        cout << "DOWN" << endl;
        return 0;
    }
    if(a[n] == 0){
        cout << "UP" << endl;
        return 0;
    }
    if(n == 1){
        cout << -1 << endl;
        return 0;
    }
    if(a[n] > a[n - 1])
        cout << "UP" << endl;
    else
        cout << "DOWN" << endl;
}