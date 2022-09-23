#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1000100;
const int MX = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int k;
int a[N];
pair < int, int > b[N];

bool can(int x)
{
    vector < int > v;
    int j = m - x + 1;
    for(int i = 1; i <= n; i++){
        while(j <= m && b[j].fi <= a[i]){
            v.pb(b[j].fi);
            j++;
        }
        v.pb(a[i]);
    }
    while(j <= m){
        v.pb(b[j].fi);
        j++;
    }
    for(int i = 0; i < v.size(); i++)
        if(i / k > v[i])
            return false;
    return true;
}

void solve()
{
    sc("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
        sc("%d", &a[i]);
    for(int i = 1; i <= m; i++){
        sc("%d", &b[i].fi);
        b[i].se = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    if(can(0) == false){
        cout << -1 << endl;
        return;
    }
    int tl = 0,
        tr = m;
    while(tl < tr){
        int tm = (tl + tr) / 2;
        if(can(tm + 1))
            tl = tm + 1;
        else
            tr = tm;
    }
    pr("%d\n", tl);
    for(int i = m - tl + 1; i <= m; i++)
        pr("%d ", b[i].se);
}

bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}