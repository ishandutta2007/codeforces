#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n, k;
int a[N];
int b[N];
int c[N];
int t[3 * N];
int tl, tr;
long long cnt;
long long s[N];
long long ans[N];

bool cmp(pair < pair < int, int >, int > x, pair < pair < int, int >, int > y)
{
        if(x.fi.fi / 300 == y.fi.fi / 300){
                return x.fi.se < y.fi.se;
        }
        return x.fi.fi < y.fi.fi;
}

void solve()
{
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> s[i];
        }
        vector < pair < long long, pair < int, int > > > v;
        for(int i = 1; i <= n; i++){
                long long x;
                cin >> x;
                if(s[i] == 2){
                        x = -x;
                }
                s[i] = s[i - 1] + x;
                v.push_back({s[i], {i, 1}});
                v.push_back({s[i] - k, {i, 2}});
                v.push_back({s[i] + k, {i, 3}});
        }
        v.push_back({0, {0, 1}});
        v.push_back({-k, {0, 2}});
        v.push_back({+k, {0, 3}});
        sort(v.begin(), v.end());
        for(int i = 0, j = 1; i < v.size(); i++){
                if(i && v[i].fi != v[i - 1].fi){
                        j++;
                }
                if(v[i].se.se == 1){
                        a[v[i].se.fi] = j;
                }
                else if(v[i].se.se == 2){
                        b[v[i].se.fi] = j;
                }
                else{
                        c[v[i].se.fi] = j;
                }
        }
        int q;
        cin >> q;
        vector < pair < pair < int, int >, int > > que;
        for(int i = 1; i <= q; i++){
                int l, r;
                cin >> l >> r;
                que.push_back({{l - 1, r}, i});
        }
        t[a[0]]++;
        sort(que.begin(), que.end(), cmp);
        for(int i = 0; i < que.size(); i++){
                int l = que[i].fi.fi, r = que[i].fi.se, h = que[i].se;
                while(tr < r){
                        tr++;
                        cnt += t[b[tr]];
                        t[a[tr]]++;
                }
                while(tl < l){
                        t[a[tl]]--;
                        cnt -= t[c[tl]];
                        tl++;
                }
                while(tl > l){
                        tl--;
                        cnt += t[c[tl]];
                        t[a[tl]]++;
                }
                while(tr > r){
                        t[a[tr]]--;
                        cnt -= t[b[tr]];
                        tr--;
                }
                ans[h] = cnt;
        }
        for(int i = 1; i <= q; i++){
                cout << ans[i] << "\n";
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