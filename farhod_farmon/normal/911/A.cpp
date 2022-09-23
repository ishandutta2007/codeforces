#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200300;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int a[N];

void solve()
{
        cin >> n;
        int mn = 1e9;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                mn = min(mn, a[i]);
        }
        int best = n - 1, last = -1e9;
        for(int i = 1; i <= n; i++){
                if(a[i] == mn){
                        best = min(best, i - last);
                        last = i;
                }
        }
        cout << best << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}