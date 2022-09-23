#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200100;

using namespace std;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 <= x2 && y1 <= y2 || x1 + y1 <= max(x2, y2))
        cout << "Polycarp" << endl;
    else
        cout << "Vasiliy" << endl;
}