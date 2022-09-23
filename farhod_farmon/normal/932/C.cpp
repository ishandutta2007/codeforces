#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long Q = 1000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int a;
int b;

void solve()
{
        cin >> n >> a >> b;
        for(int x = 0; x * a <= n; x++){
                int y = (n - x * a) / b;
                if(x * a + y * b == n){
                        int s = 1;
                        for(int i = 0; i < x; i++){
                                for(int j = 1; j < a; j++){
                                        cout << s + j << " ";
                                }
                                cout << s << " ";
                                s += a;
                        }
                        for(int i = 0; i < y; i++){
                                for(int j = 1; j < b; j++){
                                        cout << s + j << " ";
                                }
                                cout << s << " ";
                                s += b;
                        }
                        return;
                }
        }
        cout << -1 << "\n";
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