#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int q;
int m;
int a[N];
int t[N];
int l[N];
int r[N];

void solve()
{
        cin >> n >> q >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= q; i++){
                cin >> t[i] >> l[i] >> r[i];
        }
        for(int i = 1; i <= m; i++){
                int x;
                cin >> x;
                for(int j = q; j >= 1; j--){
                        if(x < l[j] || x > r[j]){
                                continue;
                        }
                        if(t[j] == 1){
                                if(x == l[j]){
                                        x = r[j];
                                }
                                else{
                                        x--;
                                }
                        }
                        else{
                                x = r[j] - (x - l[j]);
                        }
                }
                cout << a[x] << " ";
        }
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