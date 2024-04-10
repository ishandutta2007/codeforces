#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
int bad;
int a[N];
int k[N];
int b[N];

void upd(int x, int g)
{
        if(g == 1){
                bad += (k[x] == 0);
        }
        else{
                bad -= (k[x] == 1);
        }
        k[x] += g;
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int s = 0;
        for(int i = 1; i <= n; i++){
                cin >> k[i];
                bad += (k[i] > 0);
                s += k[i];
        }
        int last = 1, best = 1e9;
        upd(a[1], -1);
        for(int i = 1; i <= n; i++){
                while(last + 1 <= n && bad > 0){
                        last++;
                        upd(a[last], -1);
                }
                if(bad == 0){
                        best = min(best, last - i + 1);
                }
                upd(a[i], 1);
        }
        if(best == 1e9){
                cout << -1 << "\n";
        }
        else{
                cout << best - s << "\n";
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