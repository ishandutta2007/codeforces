#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;
const int MX = 1024;
const int MAGIC = sqrt(N);
const long long mod = 5e7 + 17;

using namespace std;

int n;
int m;
int k;
int b[MX];
int c[MX];

void solve()
{
    sc("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        int x;
        sc("%d", &x);
        b[x]++;
    }
    for(int i = 1; i <= m; i++){
        int cur = 1;
        for(int j = 0; j < MX; j++){
            if(b[j] == 0)
                continue;
            if(cur == 0){
                c[j ^ k] += b[j] / 2;
                c[j] += b[j] - b[j] / 2;
            }
            else{
                c[j] += b[j] / 2;
                c[j ^ k] += b[j] - b[j] / 2;
            }
            cur = (cur + b[j]) % 2;
        }
        for(int j = 0; j < MX; j++){
            b[j] = c[j];
            c[j] = 0;
        }
    }
    int mn = 1e9,
        mx = 0;
    for(int j = 0; j < MX; j++){
        if(b[j]){
            mn = min(mn, j);
            mx = max(mx, j);
        }
    }
    pr("%d %d\n", mx, mn);
}


bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}