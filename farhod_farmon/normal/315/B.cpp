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

long long n, m, a[N], s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++){
        int t, x, y;
        cin >> t;
        if(t == 1){
            cin >> x >> y;
            a[x] = y - s;
        }
        else if(t == 2){
            cin >> x;
            s += x;
        }
        else{
            cin >> x;
            cout << a[x] + s << endl;
        }
    }
}