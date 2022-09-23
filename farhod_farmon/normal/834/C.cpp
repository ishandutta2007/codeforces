#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 400400;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int a[N];
int b[N];
int ans[N];
vector < pair < long long, int > > v;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i];
                v.push_back({1ll * a[i] * b[i], i});
        }
        sort(v.begin(), v.end());
        for(long long l = 1, i = 0; i < v.size(); i++){
                while(l * l * l < v[i].fi){
                        l++;
                }
                if(v[i].fi == l * l * l && a[v[i].se] % l == 0 && b[v[i].se] % l == 0){
                        ans[v[i].se] = 1;
                }
        }
        for(int i = 1; i <= n; i++){
                if(ans[i]){
                        cout << "Yes" << "\n";
                }
                else{
                        cout << "No" << "\n";
                }
        }
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