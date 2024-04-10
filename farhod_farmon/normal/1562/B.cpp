#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100010;

using namespace std;

int p[N];

void solve()
{
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> c(10, 0);
        for(int i = 0; i < n; i++){
                c[s[i] - '0'] += 1;
        }
        for(int i: {4, 6, 8, 9, 1}){
                if(c[i]){
                        cout << 1 << "\n";
                        cout << i << "\n";
                        return;
                }
        }
        for(int i = 1; i < 10; i++){
                if(c[i] > 1){
                        cout << 2 << "\n";
                        cout << i  << i << "\n";
                        return;
                }
        }
        int best = 10;
        int ans;
        for(int i = 1; i < (1 << n); i++){
                int g = __builtin_popcount(i);
                if(g > 4){
                        continue;
                }
                int x = 0;
                for(int j = 0; j < n; j++){
                        if(i & (1 << j)){
                                x = x * 10 + s[j] - '0';
                        }
                }
                if(p[x]){
                        if(g < best){
                                best = g;
                                ans = x;
                        }
                }
        }
        cout << best << "\n" << ans << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        p[1]= 1;
        for(int i = 2; i < N; i++){
                for(int j = i + i; j < N; j += i){
                        p[j] = 1;
                }
        }

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}