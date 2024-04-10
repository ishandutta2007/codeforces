#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 2002 * 50;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

long long n, q;

long long get1(long long x, long long y)
{
        long long cnt = 0, f1 = (n + 1) / 2, f2 = n / 2;
        cnt += (x / 2) * f1 + (x - 1) / 2 * f2;
        if(x % 2){
                cnt += y / 2;
        }
        else{
                cnt += (y - 1) / 2;
        }
        return cnt;
}

long long get2(long long x, long long y)
{
        long long cnt = 0, f1 = n / 2, f2 = (n + 1) / 2;
        cnt += (x / 2) * f1 + (x - 1) / 2 * f2;
        if(x % 2){
                cnt += (y - 1) / 2;
        }
        else{
                cnt += y / 2;
        }
        return cnt;
}

void solve()
{
        cin >> n >> q;
        for(int i = 1; i <= q; i++){
                long long x, y;
                cin >> x >> y;
                if((x + y) % 2 == 0){
                        cout << get1(x, y) + 1 << "\n";
                }
                else{
                        cout << get2(x, y) + 1 + (n * n + 1) / 2 << "\n";
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