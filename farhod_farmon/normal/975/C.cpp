#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 101;
const long long mod = 1e9 + 7;
const long long block = 250;

using namespace std;

int n;
int q;
long long a[N];
long long s[N];
long long b[N];

void solve()
{
        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                s[i] = s[i - 1] + a[i];
        }
        long long j = 1, h = 0;
        for(int i = 1; i <= q; i++){
                long long k;
                cin >> k;
                if(a[j] - h + s[n] - s[j] <= k){
                        j = 1;
                        h = 0;
                        cout << n << "\n";
                        continue;
                }
                long long g = min(k, a[j] - h);
                h += g; k -= g;
                if(k > 0){
                        int l = j + 1, r = n;
                        while(l < r){
                                int m = (l + r) / 2;
                                if(s[m] - s[j] <= k){
                                        l = m + 1;
                                }
                                else{
                                        r = m;
                                }
                        }
                        k -= s[l - 1] - s[j];
                        j = l;
                        h = k;
                }
                else if(h == a[j]){
                        j++;
                        h = 0;
                }
                cout << n - j + 1 << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}