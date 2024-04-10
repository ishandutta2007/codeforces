#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 110;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int ans;
int a[N];
int b[N];
int c[N];
int aa[N];
int bb[N];
int cc[N];
int d[N][2020];
int p[N][2020];
int pp[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i] >> c[i];
                aa[i] = a[i];
                bb[i] = b[i];
                cc[i] = c[i];
                pp[i] = i;
        }
        sort(pp + 1, pp + n + 1, [](int i, int j){
                return b[i] < b[j];
        });
        for(int i = 1; i <= n; i++){
                a[i] = aa[pp[i]];
                b[i] = bb[pp[i]];
                c[i] = cc[pp[i]];
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j < 2020; j++){
                        d[i][j] = d[i - 1][j];
                        p[i][j] = p[i - 1][j];
                }
                for(int j = a[i]; j < b[i]; j++){
                        if(d[i - 1][j - a[i]] + c[i] > d[i][j]){
                                d[i][j] = d[i - 1][j - a[i]] + c[i];
                                p[i][j] = i;
                        }
                }
        }
        int j = 0, t;
        for(int i = 1; i < 2020; i++){
                if(d[n][i] >= ans){
                        ans = d[n][i];
                        j = p[n][i];
                        t = i;
                }
        }
        cout << ans << "\n";
        vector < int > v;
        while(j != 0){
                v.push_back(pp[j]);
                t -= a[j];
                j = p[j - 1][t];
        }
        cout << v.size() << "\n";
        reverse(v.begin(), v.end());
        for(int x: v){
                cout << x << " ";
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