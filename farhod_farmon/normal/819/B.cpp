#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000300;
const long long MX = 1000010;
const long long H = 17;
const long long MAGIC = 1000;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int cur[N];
ll s1, s2;
ll c1, c2;
vector < int > v1[N], v2[N];

void solve()
{
        sc("%d", &n);
        for(int i = 1; i <= n; i++){
                int x;
                sc("%d", &x);
                if(x <= i){
                        s2 += i - x;
                        cur[i] = i - x;
                        c2++;
                        v1[n - i + x].pb(i);
                        v2[n - i].pb(i);
                }
                else{
                        s1 += x - i;
                        cur[i] = x - i;
                        c1++;
                        v1[x - i].pb(i);
                        v2[n - i].pb(i);
                }
                a[i] = x;
        }
        ll best = 1e17, h;
        for(int i = 0; i < n; i++){
                if(s1 - c1 * i + s2 + c2 * i < best){
                        best = s1 - c1 * i + s2 + c2 * i;
                        h = i;
                }
                for(int j: v1[i]){
                        s1 -= cur[j];
                        c1--;
                        c2++;
                        cur[j] = 1 - (i + 1);
                        s2 += cur[j];
                }
                for(int j: v2[i]){
                        s2 -= cur[j];
                        c2--;
                        c1++;
                        cur[j] = a[j] - 1 + (i + 1);
                        s1 += cur[j];
                }
        }
        cout << best << " " << h << "\n";
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
                sc("%d", &TE);
        while(TE--)
                solve();
        return 0;
}