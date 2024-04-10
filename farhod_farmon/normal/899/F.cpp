#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200200;
const long long Q = 1000010;
const long long mod = 1e9 + 7;
const long long block = 500;

using namespace std;

int n;
int m;
int f[N];
string c;
char ans[N];
set < int > s[200];

void upd(int x)
{
        while(x < N){
                f[x] += 1;
                x += x & -x;
        }
}

int get(int x)
{
        int cnt = 0;
        while(x){
                cnt += f[x];
                x -= x & -x;
        }
        return cnt;
}

int fake(int x)
{
        int l = 1, r = n;
        while(l < r){
                int m = (l + r) / 2;
                if(m - get(m) < x){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        return l;
}

void solve()
{
        cin >> n >> m >> c;
        for(int i = 0; i < n; i++){
                s[c[i]].insert(i + 1);
        }
        for(int i = 1; i <= m; i++){
                int l, r;
                char c;
                cin >> l >> r >> c;
                l = fake(l); r = fake(r);
                auto p = s[c].lower_bound(l);
                while(p != s[c].end() && *p <= r){
                        upd(*p);
                        s[c].erase(p);
                        p = s[c].lower_bound(l);
                }
        }
        for(int i = 0; i < 200; i++){
                while(!s[i].empty()){
                        ans[*s[i].begin()] = i;
                        s[i].erase(s[i].begin());
                }
        }
        for(int i = 1; i <= n; i++){
                if(ans[i]){
                        cout << ans[i];
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("bootfall.in");
        //fout("bootfall.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}