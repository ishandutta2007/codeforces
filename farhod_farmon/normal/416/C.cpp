#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 1010;

using namespace std;

int n, c[N], p[N], r[N], k;
pair < int, int > v[N];
vector < pair < int, int > > ans;
bool used[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> c[i] >> p[i];
        v[i] = {p[i], i};
    }
    cin >> k;
    for(int i = 1; i <= k; i++)
        cin >> r[i];
    sort(v + 1, v + n + 1);
    int pr = 0;
    for(int i = n; i >= 1; i--){
        int id = v[i].se,
            h = -1;
        for(int j = 1; j <= k; j++){
            if(used[j] || r[j] < c[id])
                continue;
            if(h == -1 || r[j] < r[h])
                h = j;
        }
        if(h == -1)
            continue;
        used[h] = true;
        pr += p[id];
        ans.pb({id, h});
    }
    cout << ans.size() << " " << pr << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].fi << " " << ans[i].se << endl;
}