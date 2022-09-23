#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int k;
int a[N];

void merg(int l, int r, int tl, int tr)
{
        if(!k || l + 1 == r){
                for(int i = l; i < r; i++){
                        a[i] = tl + i - l;
                }
                return;
        }
        k -= 2;
        int m = (l + r) / 2;
        merg(l, m, tr - (m - l - 1), tr);
        merg(m, r, tl, tr - (m - l));
}

void solve()
{
        cin >> n >> k;
        k--;
        merg(0, n, 1, n);
        if(k != 0){
                cout << -1 << "\n";
                return;
        }
        for(int i = 0; i < n; i++){
                cout << a[i] << " ";
        }
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("landscape.in");
        //fout("landscape.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}