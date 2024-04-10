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
                vector < int > c(26, 0);
                for(int i = 1; i <= n; i++){
                        char x;
                        cin >> x;
                        c[x - 'a'] += 1;
                }
                vector < int > v;
                for(int i = 0; i < 26; i++){
                        while(c[i] && v.size() < k){
                                v.push_back(i);
                                c[i] -= 1;
                        }
                }
                if(v[k - 1] != v[0]){
                        cout << char('a' + v[k - 1]) << "\n";
                        continue;
                }
                string res = "", T = "";
                res += char('a' + v[0]);
                int cnt = 0;
                for(int i = 0; i < 26; i++){
                        if(c[i]){
                                cnt += 1;
                                while(c[i]--){
                                        T += char('a' + i);
                                }
                        }
                }
                if(cnt > 1){
                        res += T;
                } else{
                        for(int i = 0; i < (n - 1) / k; i++){
                                res += T[0];
                        }
                }
                cout << res << "\n";
        }
}