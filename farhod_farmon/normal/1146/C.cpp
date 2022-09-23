#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

void solve()
{
        int n;
        cin >> n;
        int res = 0;
        for(int i = 0; i < 9; i++){
                vector < int > a, b;
                for(int j = 1; j <= n; j++){
                        if(j & (1 << i)){
                                a.push_back(j);
                        } else{
                                b.push_back(j);
                        }
                }
                if(a.empty() || b.empty()){
                        continue;
                }
                cout << a.size() << " " << b.size();
                for(int x: a){
                        cout << " " << x;
                }
                for(int x: b){
                        cout << " " << x;
                }
                cout << endl;
                int gg;
                cin >> gg;
                res = max(res, gg);
        }
        cout << -1 << " " << res << endl;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);


        int T;
        cin >> T;
        while(T--){
                solve();
        }
}