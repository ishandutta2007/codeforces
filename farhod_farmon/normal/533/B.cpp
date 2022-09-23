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

int n;
long long a[N];
long long d[N][2];
vector < int > v[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p >> a[i];
        if(p != -1)
            v[p].pb(i);
    }
    long long ans = 0;
    for(int i = n; i >= 1; i--){
        for(auto y: v[i]){
            long long f0 = d[i][0],
                      f1 = d[i][1];
            d[i][0] = max(f0 + d[y][0], d[i][0]);
            d[i][1] = max(f0 + d[y][1], d[i][1]);
            if(f1){
                d[i][0] = max(d[i][0], f1 + d[y][1]);
                d[i][1] = max(d[i][1], f1 + d[y][0]);
            }
        }
        d[i][1] = max(d[i][1], d[i][0] + a[i]);
        ans = max(ans, d[i][1]);
    }
    cout << ans << endl;
}