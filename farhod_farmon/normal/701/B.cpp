#include <bits/stdc++.h>

#define lli long long int
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

bool c[N], r[N];
lli n, m, cnt, ax, ay;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    cnt = n * n;
    for(int i = 1; i <= m; i++){
        lli x, y;
        cin >> x >> y;
        if(!c[x]){
            c[x] = true;
            ax++;
            cnt -= n - ay;
        }
        if(!r[y]){
            r[y] = true;
            ay++;
            cnt -= n - ax;
        }
        cout << cnt << " ";
    }
}