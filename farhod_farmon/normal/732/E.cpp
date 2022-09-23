#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

int n, m;
int ans1[N];
int ans2[N];
pair < int, int > b[N];
set < pair < int, int > > s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        int x;
        sc("%d", &x);
        s.insert({x, i});
    }
    for(int i = 1; i <= m; i++){
        sc("%d", &b[i].fi);
        b[i].se = i;
    }
    int c = 0,
        u = 0;
    sort(b + 1, b + m + 1);
    for(int i = 1; i <= m; i++){
        int x = b[i].fi,
            cnt = 0;
        while(true){
            auto y = s.lower_bound({x, -1});
            if(y != s.end() && y->fi == x){
                ans1[b[i].se] = cnt;
                ans2[y->se] = b[i].se;
                c += 1;
                u += cnt;
                s.erase(y);
                break;
            }
            if(x == 1)
                break;
            else
                x = (x + 1) / 2;
            cnt++;
        }
    }
    pr("%d %d\n", c, u);
    for(int i = 1; i <= m; i++)
        pr("%d ", ans1[i]);
    pr("\n");
    for(int i = 1; i <= n; i++)
        pr("%d ", ans2[i]);
}