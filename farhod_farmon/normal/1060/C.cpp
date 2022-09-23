#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 2020;
const long long Q = 10001;
const long long mod = 1e9 + 7;;
const long long block = sqrt(N);

using namespace std;

int n;
int m;
int k;
int a[N];
int b[N];

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                a[i] += a[i - 1];
        }
        for(int i = 1; i <= m; i++){
                cin >> b[i];
                b[i] += b[i - 1];
        }
        cin >> k;
        vector < pair < int, int > > v;
        for(int i = 1; i <= n; i++){
                for(int j = i; j <= n; j++){
                        v.push_back({a[j] - a[i - 1], j - i + 1});
                }
        }
        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); i++){
                v[i].se = max(v[i].se, v[i - 1].se);
        }
        int ans = 0;
        for(int i = 1; i <= m; i++){
                for(int j = i; j <= m; j++){
                        int y = k / (b[j] - b[i - 1]);
                        int l = 0, r = v.size() - 1;
                        if(v[0].fi > y){
                                continue;
                        }
                        while(l < r){
                                int m = (l + r) / 2;
                                if(v[m + 1].fi <= y){
                                        l = m + 1;
                                }
                                else{
                                        r = m;
                                }
                        }
                        ans = max(ans, (j - i + 1) * v[l].se);
                }
        }
        cout << ans << "\n";
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