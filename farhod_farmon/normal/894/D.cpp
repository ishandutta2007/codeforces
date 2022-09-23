#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000100;
const long long Q = 10010;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int m;
long long l[N];
long long ans[N / 10];
vector < pair < int, int > > qu[N];

vector < int > dfs(int x)
{
        vector < int > v, a, b;
        if(x > n){
                return v;
        }
        l[x] += l[x / 2];
        a = dfs(x * 2);
        b = dfs(x * 2 + 1);
        int j = 0;
        v.push_back(l[x]);
        for(int i = 0; i < a.size(); i++){
                while(j < b.size() && b[j] <= a[i]){
                        v.push_back(b[j]);
                        j++;
                }
                v.push_back(a[i]);
        }
        while(j < b.size()){
                v.push_back(b[j]);
                j++;
        }
        sort(qu[x].begin(), qu[x].end());
        long long i = 0, cnt = 0;
        for(auto p: qu[x]){
                while(i < v.size() && v[i] <= p.fi + l[x]){
                        cnt += v[i];
                        i++;
                }
                ans[p.se] += 1ll * i * (p.fi + l[x]) - cnt;
        }
        return v;
}

void solve()
{
        cin >> n >> m;
        for(int i = 2; i <= n; i++){
                cin >> l[i];
        }
        for(int i = 1; i <= m; i++){
                int x, h;
                cin >> x >> h;
                qu[x].push_back({h, i});
                while(true){
                        h -= l[x];
                        if(h < 0 || x == 1){
                                break;
                        }
                        ans[i] += h;
                        if(h - l[x ^ 1] > 0){
                                qu[x ^ 1].push_back({h - l[x ^ 1], i});
                        }
                        x /= 2;
                }
        }
        dfs(1);
        for(int i = 1; i <= m; i++){
                cout << ans[i] << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("mine.in");
        //fout("mine.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}