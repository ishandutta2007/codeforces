#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 1000100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n, k;
                string s;
                cin >> n >> k >> s;
                vector < int > v = {0};
                int res = 0;
                for(int i = 0; i < n; i++){
                        if(s[i] == 'W'){
                                res += 1;
                                v.push_back(0);
                        } else{
                                v.back() += 1;
                        }
                }
                if(v.size() == 1){
                        cout << max(0, k * 2 - 1) << "\n";
                        continue;
                }
                vector < int > nv;
                for(int i = 1; i < v.size() - 1; i++){
                        nv.push_back(v[i]);
                }
                sort(nv.begin(), nv.end());
                for(int x: nv){
                        int g = min(k, x);
                        res += g * 2;
                        k -= g;
                        if(g == x){
                                res += 1;
                        }
                }
                res += 2 * min(v.back() + v[0], k);

                cout << res << "\n";
        }
}