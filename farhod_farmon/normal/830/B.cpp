#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int t[N];
vector < int > v[N];

void upd(int x, int g)
{
        while(x < N){
                t[x] += g;
                x += x & -x;
        }
}

int get(int x)
{
        int cnt = 0;
        while(x > 0){
                cnt += t[x];
                x -= x & -x;
        }
        return cnt;
}

int query(int i, int j)
{
        if(i <= j){
                return get(j) - get(i - 1);
        }
        return get(n) - get(i - 1) + get(j);
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                v[a[i]].push_back(i);
                upd(i, 1);
        }
        long long ans = 0, s = 1;
        for(int i = 1; i < N; i++){
                if(v[i].empty()) continue;
                int l = 0, r = v[i].size();
                while(l < r){
                        int m = (l + r) / 2;
                        if(v[i][m] < s){
                                l = m + 1;
                        }
                        else{
                                r = m;
                        }
                }
                l %= (int)v[i].size();
                for(int j = 0; j < v[i].size(); j++){
                        ans += query(s, v[i][(l + j) % (int)v[i].size()]);
                        s = v[i][(l + j) % (int)v[i].size()];
                        upd(s, -1);
                }
        }
        cout << ans << "\n";
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