#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 3000100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

long long n, d;
vector < long long > v;

void solve()
{
        cin >> n >> d;
        long long x = 1;
        while(n > 0){
                long long l = 1;
                while((1ll << (l + 1)) - 1 <= n){
                        l++;
                }
                n -= (1ll << l) - 1;
                for(int i = 0; i < l; i++){
                        v.push_back(x);
                }
                x += d + 1;
        }
        cout << v.size() << endl;
        for(long long a: v){
                cout << a << " ";
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