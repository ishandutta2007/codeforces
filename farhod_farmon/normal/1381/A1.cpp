#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

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
                vector < int > a(n), b(n);
                for(int i = 0; i < n; i++){
                        char c;
                        cin >> c;
                        a[i] = c - '0';
                }
                for(int i = 0; i < n; i++){
                        char c;
                        cin >> c;
                        b[i] = c - '0';
                }
                vector < int > res;
                int rev = 0, l = 0, r = n - 1;
                for(int i = n - 1; i >= 0; i--){
                        int cur = a[r], shit = a[l];
                        if(rev == 1){
                                cur = a[l] ^ 1;
                                shit = a[r] ^ 1;
                        }
                        if(cur == b[i]){
                                if(rev == 1){
                                        l += 1;
                                } else{
                                        r -= 1;
                                }
                                continue;
                        }
                        if(shit == b[i]){
                                res.push_back(1);
                        }
                        res.push_back(i + 1);
                        rev ^= 1;
                        if(rev){
                                l += 1;
                        } else{
                                r -= 1;
                        }
                }
                cout << res.size();
                for(int x: res) cout << " " << x;
                cout << "\n";
        }
}