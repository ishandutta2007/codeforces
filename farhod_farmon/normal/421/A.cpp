#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

int n, a, b;
int ans[111];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> a >> b;
    for(int i = 1; i <= a; i++){
        int x;
        cin >> x;
        ans[x] = 1;
    }
    for(int i = 1; i <= n; i++)
        cout << 2 - ans[i] << " ";
}