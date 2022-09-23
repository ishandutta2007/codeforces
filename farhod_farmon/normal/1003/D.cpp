#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = N * 30;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int q;
int a[40];
int b[40];

int get(int x)
{
        int need = 1, c = 0;
        while(x >= 0){
                int g = min(need, b[x]);
                need -= g;
                b[x] -= g;
                c += g;
                need *= 2;
                x--;
        }
        if(need){
                c = -1;
        }
        return c;
}

void solve()
{
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                int x, l = 0;
                cin >> x;
                while(1 << l < x){
                        l++;
                }
                a[l]++;
        }
        for(int i = 1; i <= q; i++){
                int x, c = 0;
                cin >> x;
                for(int j = 0; j < 40; j++){
                        b[j] = a[j];
                }
                for(int j = 30; j >= 0; j--){
                        if(x & (1 << j)){
                                int g = get(j);
                                if(g == -1){
                                        c = -1e9;
                                }
                                else{
                                        c += g;
                                }
                        }
                }
                cout << max(-1, c) << "\n";
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