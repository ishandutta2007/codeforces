#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
long long d[N];
vector < pair < long long, int > > v;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                long long l, r;
                cin >> l >> r;
                v.push_back({l, 1});
                v.push_back({r + 1, -1});
        }
        sort(v.begin(), v.end());
        long long cnt = 0;
        for(int i = 0; i < v.size(); i++){
                cnt += v[i].se;
                if(i + 1 < v.size() && v[i].fi != v[i + 1].fi){
                        d[cnt] += v[i + 1].fi - v[i].fi;
                }
        }
        for(int i = 1; i <= n; i++){
                cout << d[i] << " ";
        }
}

bool mtest = false; int main()
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