#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

long double a, d;
int n;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> a >> d;
    cin >> n;
    long double s = 0;
    int g = 0;
    for(int i = 1; i <= n; i++){
        s += d;
        int k = s / a;
        s -= a * k;
        g = (g + k) % 4;
        cout << fixed << setprecision(6);
        if(g == 0)
            cout << s << " " << 0.000000 << endl;
        if(g == 1)
            cout << a << " " << s << endl;
        if(g == 2)
            cout << a - s << " " << a << endl;
        if(g == 3)
            cout << 0.000000 << " " << a - s << endl;
    }
}