#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

vector < long long > v;

int f(long long x)
{
        int l = 0, r = v.size() - 1;
        while(l < r){
                int m = (l + r) / 2;
                if(v[m + 1] <= x){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        return l;
}

map < long long, bool > used;

void rec(long long x, int g, int n)
{
        if(n > 18 || g > 3 || used.find(x) != used.end()){
                return;
        }
        v.push_back(x);
        used[x] = 1;
        for(int i = 0; i < 10; i++){
                rec(x * 10 + i, g + (i > 0), n + 1);
        }
}

void solve()
{
        rec(0, 0, 0);
        v.push_back(1e18);
        sort(v.begin(), v.end());
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                long long l, r;
                cin >> l >> r;
                cout << f(r) - f(l - 1) << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}