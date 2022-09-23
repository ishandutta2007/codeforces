#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 300300;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

long long n;
long long k;

void solve()
{
        cin >> n >> k;
        long long l = 1, r = n + 1;
        while(l < r){
                long long m = (l + r) / 2 + 1;
                if(m * (m - 1) / 2 <= k){
                        l = m;
                }
                else{
                        r = m - 1;
                }
        }
        k -= l * (l - 1) / 2;
        if(l == n + 1 || l == n && k > 0){
                cout << "Impossible" << "\n";
                return;
        }
        for(int i = 0; i < l; i++){
                cout << "(";
        }
        for(int i = l - 1; i >= 0; i--){
                if(i + 1 == k){
                        cout << "()";
                        l++;
                }
                cout << ")";
        }
        for(int i = 0; i < n - l; i++){
                cout << "()";
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