#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 202;
const long long Q = 10010;
const long long mod = 1000000007;
const long long block = 500;

using namespace std;

int n;

int f(int k)
{
        return ((1 << k) - 1) * (1 << (k - 1));
}

void solve()
{
        cin >> n;
        int mx = 0;
        for(int i = 1; f(i) <= n; i++){
                if(n % f(i) == 0){
                        mx = max(mx, f(i));
                }
        }
        cout << mx << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}