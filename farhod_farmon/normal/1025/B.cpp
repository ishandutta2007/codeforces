#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 150100;
const long long Q = 10100;
const long long mod = 998244353;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
int b[N];

bool good(int x)
{
        for(int i = 1; i <= n; i++){
                if(a[i] % x != 0 && b[i] % x != 0){
                        return false;
                }
        }
        return true;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i];
        }
        vector < int > v;
        long long x = a[1];
        for(long long i = 2; i * i <= x; i++){
                if(x % i == 0){
                        v.push_back(i);
                        while(x % i == 0){
                                x /= i;
                        }
                }
        }
        if(x > 1){
                v.push_back(x);
        }
        x = b[1];
        for(long long i = 2; i * i <= x; i++){
                if(x % i == 0){
                        v.push_back(i);
                        while(x % i == 0){
                                x /= i;
                        }
                }
        }
        if(x > 1){
                v.push_back(x);
        }
        for(int x: v){
                if(good(x)){
                        cout << x << "\n";
                        return;
                }
        }
        cout << -1 << "\n";
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