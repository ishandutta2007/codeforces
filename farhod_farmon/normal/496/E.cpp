#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n, m, ans[N], k[N];
pair < pair < int, int >, int > a[N], b[N];
set < pair < int, int > > s;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> b[i].fi.fi >> b[i].fi.se >> k[i];
        b[i].se = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for(int i = 1, j = 1; i <= n; i++){
        while(b[j].fi.fi <= a[i].fi.fi && j <= m){
            s.insert({b[j].fi.se, b[j].se});
            j++;
        }
        if(s.empty()){
            cout << "NO" << endl;
            return 0;
        }
        auto it = s.lower_bound({a[i].fi.se, -1});
        if(it == s.end()){
            cout << "NO" << endl;
            return 0;
        }
        ans[a[i].se] = it->se;
        k[it->se]--;
        if(k[it->se] == 0)
            s.erase(it);
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}