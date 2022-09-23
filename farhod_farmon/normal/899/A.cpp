#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 1000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int a[3];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a[x]++;
        }
        int g = min(a[1], a[2]);
        cout << g + (a[1] - g) / 3 << "\n";
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