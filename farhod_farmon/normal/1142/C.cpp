#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
pair < long long, long long > a[N];

int orien(int i, int j, int h)
{
        long long o = (a[j].fi - a[i].fi) * (a[h].se - a[i].se) - (a[j].se - a[i].se) * (a[h].fi - a[i].fi);
        if(o > 0){
                return 1; // anti
        } else if(o < 0){
                return -1;
        }
        return 0;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi >> a[i].se;
                a[i].se -= a[i].fi * a[i].fi;
        }
        sort(a + 1, a + n + 1);
        vector < int > res;
        for(int i = 1; i <= n; i++){
                if(i + 1 <= n && a[i].fi == a[i + 1].fi){
                        continue;
                }
                int l = res.size();
                while(l > 1 && orien(res[l - 2], res[l - 1], i) != -1){
                        res.pop_back();
                        l--;
                }
                res.push_back(i);
        }
        cout << res.size() - 1 << "\n";
}