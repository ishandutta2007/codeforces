#include <bits/stdc++.h>

#define fi first
#define se second
#define pt pair < double, double >

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n, 0);
                for(int i = 0; i < n; i++){
                        a[i] = i;
                }
                long long C = 0;
                vector < pair < int, int > > res;
                for(int i = 1; i < n; i++){
                        int x = max(i, n - i - 1);
                        C += 1ll * x * x;
                        if(i >= n - i - 1){
                                res.push_back({i, 0});
                        } else{
                                res.push_back({i, n - 1});
                        }
                }
                for(int i = res.size() - 1; i >= 0; i--){
                        swap(a[res[i].fi], a[res[i].se]);
                }
                cout << C << "\n";
                for(int x: a){
                        cout << x + 1 << " ";
                }
                cout << "\n" << res.size() << "\n";
                for(auto p: res){
                        cout << p.fi + 1 << " " << p.se + 1 << "\n";
                }
        }
}