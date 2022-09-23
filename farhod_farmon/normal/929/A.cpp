#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1010;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n;
int k;
int a[N];
int d[N];

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                d[i] = 1e9;
        }
        d[1] = 0;
        for(int i = 2; i <= n; i++){
                for(int j = 1; j < i; j++){
                        if(a[i] - a[j] <= k){
                                d[i] = min(d[i], d[j] + 1);
                        }
                }
        }
        if(d[n] == 1e9){
                cout << -1 << "\n";
        }
        else{
                cout << d[n] << "\n";
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