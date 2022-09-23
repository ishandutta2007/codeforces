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

int n, m, k;
int a[N];
int p[N];
vector < int > v[N];

int get(int x)
{
    if(x == p[x])
        return x;
    return p[x] = get(p[x]);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = i;
    }
    for(int i = 1; i <= m; i++){
        int l, r;
        cin >> l >> r;
        l = get(l);
        r = get(r);
        if(l != r)
            p[l] = r;
    }
    for(int i = 1; i <= n; i++)
        v[get(i)].pb(a[i]);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(v[i].empty())
            continue;
        sort(v[i].begin(), v[i].end());
        int cnt = 0,
            mx = 0,
            last = -1;
        for(auto x: v[i]){
            if(x == last)
                cnt++;
            else
                cnt = 1;
            last = x;
            mx = max(mx, cnt);
        }
        ans += v[i].size() - mx;
    }
    cout << ans << endl;
}