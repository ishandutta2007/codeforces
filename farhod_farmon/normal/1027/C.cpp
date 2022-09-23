#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000100;
const long long Q = 10100;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];
int c[Q];
long double ans, x, y;

void upd(long double a, long double b)
{
        if((a + a + b + b) * (a + a + b + b) / (a * b) < ans){
                ans = (a + a + b + b) * (a + a + b + b) / (a * b);
                x = a;
                y = b;
        }
}

void solve()
{
        cin >> n;
        vector < int > v;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                c[a[i]]++;
        }
        ans = 1e18;
        for(int i = 1; i <= n; i++){
                if(c[a[i]] > 1){
                        v.push_back(a[i]);
                        if(c[a[i]] > 3){
                                upd(a[i], a[i]);
                        }
                }
                c[a[i]] = 0;
        }
        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); i++){
                upd(v[i - 1], v[i]);
        }
        cout << x << " " << x << " " << y << " " << y << "\n";
}

bool mtest = true; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("island.in");
        //fout("island.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}