#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 15000000;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int b[300300];
int G;
int d[N][2];
int c[N][2];

int get(int x)
{
        int y = 0, f = 0;
        for(int i = 29; i >= 0; i--){
                int g = (x >> i) & 1;
                if(c[f][g]){
                        f = d[f][g];
                        if(g == 1){
                                y += (1 << i);
                        }
                }
                else{
                        f = d[f][1 ^ g];
                        if(g == 0){
                                y += (1 << i);
                        }
                }
        }
        return y;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> b[i];
        }
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                int f = 0;
                for(int j = 29; j >= 0; j--){
                        int g = (x >> j) & 1;
                        if(!d[f][g]){
                                G++;
                                d[f][g] = G;
                        }
                        c[f][g]++;
                        f = d[f][g];
                }
        }
        for(int i = 1; i <= n; i++){
                int a = get(b[i]);
                cout << (b[i] ^ a) << " ";
                int f = 0;
                for(int j = 29; j >= 0; j--){
                        int g = (a >> j) & 1;
                        c[f][g]--;
                        f = d[f][g];
                }
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