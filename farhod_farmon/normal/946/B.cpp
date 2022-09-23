#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 7;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

long long a, b;

void solve()
{
        cin >> a >> b;
        while(a > 0 && b > 0){
                if(a >= 2 * b){
                        a %= 2 * b;
                }
                else if(b >= 2 * a){
                        b %= 2 * a;
                }
                else{
                        break;
                }
        }
        cout << a << " " << b << "\n";
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