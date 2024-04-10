#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 10100;

using namespace std;

int x, y;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        if(c == 'F')
            x++;
        if(c == 'I')
            y++;
    }
    if(y > 1)
        cout << 0 << endl;
    else if(y == 1)
        cout << 1 << endl;
    else
        cout << n - x << endl;
}