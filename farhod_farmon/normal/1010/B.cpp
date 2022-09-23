#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int m;
int n;
int a[N];

void solve()
{
        cin >> m >> n;
        for(int i = 1; i <= n; i++){
                cout << m << endl;
                int x;
                cin >> x;
                if(x == 0){
                        return;
                }
                if(x == -1){
                        a[i] = 1;
                }
        }
        int l = 1, r = m, h = 1;
        while(l <= r){
                int m = (l + r) / 2;
                cout << m << endl;
                int g;
                cin >> g;
                if(a[h] == 0){
                        g = - g;
                }
                if(g == -1){
                        r = m - 1;
                }
                else{
                        l = m + 1;
                }
                if(h == n){
                        h = 1;
                }
                else{
                        h++;
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