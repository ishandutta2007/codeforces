#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n, m;
                cin >> n >> m;
                vector < pair < int, int > > a(m);
                for(int i = 0; i < m; i++){
                        cin >> a[i].fi >> a[i].se;
                }
                sort(a.begin(), a.end());
                vector < int > b;
                for(int i = 0; i < m; i++){
                        b.push_back(i);
                }
                sort(b.begin(), b.end(), [&](int x, int y){
                        return a[x].se < a[y].se;
                });
                int cnt = 0;
                long long res = 0, sum = 0;
                vector < int > used(m, 0);
                for(int i = m - 1, j = m - 1; i >= 0; i--){
                        while(j >= 0 && a[j].fi >= a[b[i]].se && cnt < n){
                                cnt += 1;
                                sum += a[j].fi;
                                used[j] = true;
                                j -= 1;
                        }
                        if(cnt == n){
                                res = max(res, sum);
                                break;
                        }
                        int g = 0, to_add = 0;
                        if(!used[b[i]]){
                                g = 1;
                                to_add = a[b[i]].fi;
                        }
                        //cout << i << " " << b[i] << " " << cnt << " " << sum << endl;
                        res = max(res, sum + to_add + 1ll * (n - cnt - g) * a[b[i]].se);
                }
                cout << res << "\n";
        }
}