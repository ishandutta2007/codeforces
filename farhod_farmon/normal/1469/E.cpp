#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n, k;
                string s;
                cin >> n >> k >> s;
                int len = 0;
                while((1 << len) <= n){
                        len += 1;
                }
                len = min(len, k);
                vector < int > c(1 << len, 0);
                vector < int > f(n, 0);
                for(int i = 0; i < n; i++){
                        f[i] = s[i] - '0';
                        if(i > 0){
                                f[i] += f[i - 1];
                        }
                }
                for(int i = k - 1; i < n; i++){
                        int mask = 0;
                        for(int j = 0; j < len; j++){
                                if(s[i - j] == '0'){
                                        mask |= (1 << j);
                                }
                        }
                        int good = 1;
                        if(k != len){
                                int cnt = f[i - len];
                                if(i != k - 1){
                                        cnt -= f[i - k];
                                }
                                if(cnt < k - len){
                                        good = 0;
                                }
                        }
                        if(good){
                                c[mask] += 1;
                        }
                }
                int mask = 0;
                while(c[mask] && mask < (1 << len)){
                        mask += 1;
                }
                if(mask == (1 << len)){
                        cout << "NO" << "\n";
                        continue;
                }
                cout << "YES" << "\n";
                for(int i = 0; i < k - len; i++){
                        cout << 0;
                }
                for(int i = 0; i < len; i++){
                        if(mask & (1 << len - i - 1)){
                                cout << 1;
                        } else{
                                cout << 0;
                        }
                }
                cout << "\n";
        }
}