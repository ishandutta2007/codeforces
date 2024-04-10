#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 1000100;
const long long H = 1 << 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int l[N];
int r[N];
int d1[N];
int d2[N];

bool eq(long double x, long double y)
{
        if(x - y > 1e-13){
                return false;
        }
        if(y - x > 1e-13){
                return false;
        }
        return true;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        l[1] = a[1];
        d1[1] = 1;
        for(int i = 2; i <= n; i++){
                l[i] = l[i - 1];
                d1[i] = d1[i - 1];
                if(l[i] == a[i]){
                        d1[i]++;
                }
                else if(a[i] < l[i]){
                        l[i] = a[i];
                        d1[i] = 1;
                }
        }
        r[n] = a[n];
        d2[n] = 1;
        for(int i = n - 1; i >= 1; i--){
                r[i] = r[i + 1];
                d2[i] = d2[i + 1];
                if(r[i] == a[i]){
                        d2[i]++;
                }
                else if(a[i] < r[i]){
                        r[i] = a[i];
                        d2[i] = 1;
                }
        }
        long double ans = log(a[1]) + log(a[2]) + log(a[3]);
        for(int i = 2; i < n; i++){
                long double b = log(l[i - 1]) + log(a[i]) + log(r[i + 1]);
                ans = min(ans, b);
        }
        ll cnt = 0;
        for(int i = 2; i < n; i++){
                if(eq(ans, log(l[i - 1]) + log(a[i]) + log(r[i + 1]))){
                        cnt += 1ll * d1[i - 1] * d2[i + 1];
                }
        }
        cout << cnt << endl;
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