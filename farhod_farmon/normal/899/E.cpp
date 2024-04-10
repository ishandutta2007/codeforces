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
int a[N];
int p[N];
set < pair < int, int > > s, t;

void del(int x)
{
        s.erase({x, p[x]});
        t.erase({p[x], -x});
}

void add(int x)
{
        s.insert({x, p[x]});
        t.insert({p[x], -x});
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; ){
                int g = 0;
                while(i + g <= n && a[i] == a[i + g]){
                        g++;
                }
                p[i] = g;
                add(i);
                i += g;
        }
        int cnt = 0;
        while(!s.empty()){
                cnt++;
                int x = -(--t.end())->se;
                del(x);
                auto g = s.lower_bound({x, 0});
                if(g != s.end() && g != s.begin()){
                        int r = g->fi;
                        g--;
                        int l = g->fi;
                        if(a[l] == a[r]){
                                del(l);
                                del(r);
                                p[l] += p[r];
                                add(l);
                        }
                }
        }
        cout << cnt << "\n";
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