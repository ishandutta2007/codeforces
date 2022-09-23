#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int mod = 1e9 + 7;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n, k;
                cin >> n >> k;
                int cnt = 0;
                vector < int > dead(n + 1, 0);
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                        if(!dead[x]){
                                dead[x] = 1;
                                cnt += 1;
                        }
                }
                if(cnt > k){
                        cout << -1 << "\n";
                        continue;
                }
                vector < int > v;
                for(int i = 1; i <= n; i++){
                        if(!dead[i] && cnt < k){
                                dead[i] = 1;
                                cnt += 1;
                        }
                        if(dead[i]){
                                v.push_back(i);
                        }
                }
                cout << k * n << "\n";
                for(int i = 1; i <= n; i++){
                        for(int j = 0; j < k; j++){
                                cout << v[j] << ' ';
                        }
                }
                cout << "\n";
        }
}