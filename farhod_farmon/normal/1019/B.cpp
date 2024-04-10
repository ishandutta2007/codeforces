#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = N * 30;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int used[N];
int d[N];

int get(int x)
{
        if(x > n){
                x -= n;
        }
        if(used[x] == 0){
                cout << "? " << x << endl;
                cin >> d[x];
                used[x] = 1;
        }
        return d[x];
}

int sign(int x)
{
        if(get(x) < get(x + n / 2)){
                return 1;
        }
        if(get(x) > get(x + n / 2)){
                return -1;
        }
        return 0;
}

void solve()
{
        cin >> n;
        if(n % 4){
                cout << "! " << -1 << endl;
                return;
        }
        if(sign(1) == 0){
                cout << "! " << 1 << endl;
                return;
        }
        int l = 1, r = n / 2;
        while(l < r){
                int m = (l + r) / 2;
                if(sign(m) == 0){
                        cout << "! " << m << endl;
                        return;
                }
                if(sign(m) == sign(1)){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        cout << "! " << l << endl;
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