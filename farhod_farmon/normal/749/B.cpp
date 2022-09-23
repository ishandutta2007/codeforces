#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;
const int MX = 10010;

using namespace std;

int x[3];
int y[3];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    for(int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
    cout << 3 << endl;
    for(int i = 0; i < 3; i++)
        cout << x[(i + 2) % 3] - x[i] + x[(i + 1) % 3] << " " << y[(i + 2) % 3] - y[i] + y[(i + 1) % 3] << endl;
}