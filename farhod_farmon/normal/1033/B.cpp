#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 3003;
const long long Q = 10001;
const long long mod = 1e9 + 7;;
const long long block = sqrt(N);

using namespace std;

void solve()
{
        long long a, b;
        cin >> a >> b;
        if(a - b > 1){
                cout << "NO" << "\n";
                return;
        }
        a += b;
        for(long long i = 2; i * i <= a; i++){
                if(a % i == 0){
                        cout << "NO" << "\n";
                        return;
                }
        }
        cout << "YES" << "\n";
}

bool mtest = true; int main()
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