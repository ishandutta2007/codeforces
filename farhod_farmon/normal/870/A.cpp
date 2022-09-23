#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int m;
int a[N];
int b[N];

bool f(int x)
{
        bool f1 = false, f2 = false;
        while(x){
                for(int i = 1; i <= n; i++){
                        if(x % 10 == a[i]){
                                f1 = true;
                        }
                }
                for(int i = 1; i <= m; i++){
                        if(x % 10 == b[i]){
                                f2 = true;
                        }
                }
                x /= 10;
        }
        return (f1 & f2);
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
                cin >> b[i];
        }
        for(int i = 1; ; i++){
                if(f(i)){
                        cout << i << "\n";
                        return;
                }
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