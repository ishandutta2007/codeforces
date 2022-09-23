#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 5050;

using namespace std;

int ans[N];

int get(int x, int y)
{
    cout << "? " << x << " " << y << endl;
    fflush(stdout);
    int g;
    cin >> g;
    return g;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int a = get(1, 2);
    int b = get(2, 3);
    int c = get(1, 3);
    ans[1] = (a - b + c) / 2;
    ans[2] = a - ans[1];
    ans[3] = c - ans[1];
    for(int i = 4; i <= n; i++)
        ans[i] = get(1, i) - ans[1];
    cout << "! ";
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
    return 0;
}