#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int l[N];
int r[N];
int t[3 * N];
int p[3 * N];
vector < pair < int, int > > v;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> l[i] >> r[i];
                v.push_back({l[i], -i});
                v.push_back({r[i], i});
                v.push_back({r[i] + 1, 0});
        }
        sort(v.begin(), v.end());
        for(int i = 0, j = 0; i < v.size(); i++){
                if(i == 0 || v[i].fi != v[i - 1].fi){
                        j++;
                }
                if(v[i].se < 0){
                        l[-v[i].se] = j;
                }
                else if(v[i].se > 0){
                        r[v[i].se] = j;
                }
        }
        for(int i = 1; i <= n; i++){
                t[l[i]]++;
                t[r[i] + 1]--;
        }
        for(int i = 1; i <= 3 * n; i++){
                t[i] += t[i - 1];
                if(t[i] <= 1){
                        p[i] = 1;
                }
                p[i] += p[i - 1];
        }
        for(int i = 1; i <= n; i++){
                if(p[r[i]] - p[l[i] - 1] == 0){
                        cout << i << "\n";
                        return;
                }
        }
        cout << -1 << "\n";
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