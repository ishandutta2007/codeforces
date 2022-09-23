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

int n, a, b, k;
char c[N];
vector < int > ans;
vector < pair < int, int > > v;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d %d %d %d\n%s\n", &n, &a, &b, &k, &c);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(c[i] == '1')
            continue;
        int sz = 0;
        while(i + sz < n && c[i + sz] == '0')
            sz++;
        if(sz >= b){
            cnt += sz / b;
            v.pb({sz / b, i});
        }
        i += sz - 1;
    }
    if(cnt < a){
        pr("0\n");
        return 0;
    }
    cnt = cnt - a + 1;
    for(int i = 0; i < v.size(); i++){
        int g = min(v[i].fi, cnt);
        cnt -= g;
        for(int j = 1; j <= g; j++)
            ans.pb(v[i].se + j * b);
    }
    pr("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        pr("%d ", ans[i]);
}