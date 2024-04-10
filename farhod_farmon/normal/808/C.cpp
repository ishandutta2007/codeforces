#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long MX = 30030;
const long long MAGIC = 30;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int w;
int b[N];
pair < int, int > a[N];

void solve()
{
        cin >> n >> w;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi;
                a[i].se = i;
        }
        sort(a + 1, a + n + 1);
        int pre = 0;
        for(int i = 1; i <= n; i++){
                int need = (a[i].fi + 1) / 2;
                need = max(need, pre);
                if(need > a[i].fi){
                        cout << -1 << endl;
                        return;
                }
                w -= need;
                b[a[i].se] = need;
                pre = need;
        }
        if(w < 0){
                cout << -1 << endl;
                return;
        }
        for(int i = n; i >= 1; i--){
                int can = a[i].fi - b[a[i].se];
                can = min(can, w);
                b[a[i].se] += can;
                w -= can;
        }
        if(w != 0){
                cout << -1 << endl;
                return;
        }
        for(int i = 1; i <= n; i++){
                cout << b[i] << " ";;
        }
}


bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("unionday.in");
        //fout("unionday.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}