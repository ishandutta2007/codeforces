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

int a[3];

void f(int t1, int t2, int t3)
{
        for(int i = max(t1, max(t2, t3)); i <= 10000; i++){
                if((i - t1) % a[0] == 0) continue;
                if((i - t2) % a[1] == 0) continue;
                if((i - t3) % a[2] == 0) continue;
                return;
        }
        cout << "YES" << "\n";
        exit(0);
}

void solve()
{
        cin >> a[0] >> a[1] >> a[2];
        for(int i = 2; i <= 1500; i++){
                f(0, 1, i);
                f(1, 0, i);
                f(1, i, 0);
                f(0, i, 1);
                f(i, 1, 0);
                f(i, 0, 1);
        }
        cout << "NO" << "\n";
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