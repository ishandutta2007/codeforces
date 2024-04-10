#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 10100;
const long long Q = 1000100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

long long n, k;
set < long long > s;

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
                if(s.find(n % i) == s.end()){
                        s.insert(n % i);
                }
                else{
                        cout << "No" << "\n";
                        return;
                }
        }
        cout << "Yes" << "\n";
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