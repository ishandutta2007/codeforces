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
int d[66];

void solve()
{
    cin >> n;
    for(int i = 0; i <= 60; i++){
        int x = i;
        for(int j = 1; j <= x; j++){
            d[i]++;
            x -= j;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt ^= d[x];
    }
    if(cnt)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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