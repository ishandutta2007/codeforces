#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 5000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int m;

bool P(int x)
{
        for(int i = 2; i * i <= x; i++){
                if(x % i == 0){
                        return false;
                }
        }
        return true;
}

void solve()
{
        cin >> n >> m;
        int p = n;
        while(!P(p)){
                p++;
        }
        int w = p - (n - 2);
        cout << p << " " << p << "\n";
        cout << 1 << " " << 2 << " " << w << "\n";
        for(int i = 2; i < n; i++){
                cout << i << " " << i + 1 << " " << 1 << "\n";
        }
        m -= n - 1;
        for(int i = 1; i <= n; i++){
                for(int j = i + 2; j <= n && m; j++){
                        m--;
                        cout << i << " " << j << " " << 10000000 << "\n";
                }
        }
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