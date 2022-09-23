#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;

void solve()
{
        cin >> n;
        cout << 'z';
        for(int i = 0; n > 0; i++){
                int c = 1;
                while(c * (c + 1) / 2 <= n){
                        c++;
                }
                n -= c * (c - 1) / 2;
                while(c){
                        cout << char('a' + i);
                        c--;
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}