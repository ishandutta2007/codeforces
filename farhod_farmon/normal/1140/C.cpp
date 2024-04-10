#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 1e9 + 7;

using namespace std;

int n;
vector < pair < int, int > > v;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                int x, y;
                cin >> x >> y;
                v.push_back({y, x});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        long long res = 0, f = 0;
        set < pair < int, int > > s;
        for(int i = 0; i < n; i++){
                s.insert({v[i].se, i});
                f += v[i].se;
                if(s.size() == k + 1){
                        f -= s.begin()->fi;
                        s.erase(s.begin());
                }
                res = max(res, f * v[i].fi);
        }
        cout << res << "\n";
}