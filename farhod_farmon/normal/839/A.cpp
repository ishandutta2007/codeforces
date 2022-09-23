#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2550;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int k;
int s;

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                s += x;
                int g = min(8, min(s, k));
                s -= g;
                k -= g;
                if(!k){
                        cout << i << "\n";
                        return;
                }
        }
        cout << -1 << "\n";
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