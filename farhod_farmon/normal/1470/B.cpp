#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 1000001;

int f[N];
bool good[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        for(int i = 1; i < N; i++){
                f[i] = 1;
        }
        for(int i = 2; i < N; i++){
                if(good[i]){
                        continue;
                }
                for(int j = i; j < N; j += i){
                        good[j] = true;
                        int cnt = 0, x = j;
                        while(x % i == 0){
                                x /= i;
                                cnt ^= 1;
                        }
                        if(cnt){
                                f[j] *= i;
                        }
                }
        }

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        a[i] = f[a[i]];
                }
                sort(a.begin(), a.end());
                int cur0 = 0, cur1 = 0;
                for(int i = 0; i < a.size(); i++){
                        int cnt = 0;
                        while(i + cnt < a.size() && a[i + cnt] == a[i]){
                                cnt += 1;
                        }
                        cur0 = max(cur0, cnt);
                        if(cnt % 2 == 0 || a[i] == 1){
                                cur1 += cnt;
                        }
                        i += cnt - 1;
                }
                int q;
                cin >> q;
                while(q--){
                        long long w;
                        cin >> w;
                        if(w == 0){
                                cout << cur0 << "\n";
                        } else{
                                cout << max(cur0, cur1) << "\n";
                        }
                }
        }
}