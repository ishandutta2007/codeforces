#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 220;
const long long Q = 6000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;

void solve()
{
        cin >> n;
        int last = 0;
        for(int i = 1; i <= n; i++){
                int l, r;
                cin >> l >> r;
                l = max(l, last + 1);
                if(l <= r){
                        cout << l << " ";
                        last = l;
                }
                else{
                        cout << 0 << " ";
                }
        }
        cout << "\n";
}

bool mtest = true; int main()
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