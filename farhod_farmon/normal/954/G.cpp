#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 500500;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long block = sqrt(N);

using namespace std;

int n, r;
long long k;
long long a[N];
long long s[N];
long long d[N];

bool can(long long m)
{
        for(int i = 0; i <= n; i++){
                d[i] = s[i];
        }
        long long cnt = 0;
        for(int i = 1; i <= n; i++){
                d[i] += d[i - 1];
                if(d[i] < m){
                        long long g = m - d[i];
                        cnt += g;
                        d[i] += g;
                        d[min(n, i + r + r) + 1] -= g;
                        if(cnt > k){
                                break;
                        }
                }
        }
        return cnt <= k;
}

void solve()
{
        cin >> n >> r >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                s[max(0, i - r)] += a[i];
                s[min(n, i + r) + 1] -= a[i];
        }
        long long l = 0, r = 2e18;
        while(l < r){
                long long m = (l + r) / 2;
                if(can(m + 1)){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        cout << l << "\n";
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