#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 330;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n), res, used(n + 1, 0);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                while(true){
                        for(int i = 0; i <= n; i++) used[i] = 0;
                        for(int x: a) used[x] = 1;
                        int m = 0;
                        while(used[m]){
                                m += 1;
                        }

                        if(m < n && a[m] != m){
                                a[m] = m;
                                res.push_back(m);
                                continue;
                        }

                        bool done = true;
                        for(int i = 0; i < m; i++){
                                if(a[i] != i){
                                        a[i] = m;
                                        res.push_back(i);
                                        done = false;
                                        break;
                                }
                        }
                        if(done){
                                break;
                        }
                }
                assert((int)res.size() <= 2 * n);
                cout << res.size() << "\n";
                for(int x: res){
                        cout << x + 1 << " ";
                }
                cout << "\n";
        }
}