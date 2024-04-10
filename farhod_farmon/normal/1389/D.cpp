#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n, l1, r1, l2, r2;
                long long k;
                cin >> n >> k >> l1 >> r1 >> l2 >> r2;
                int A = 0, B = 0;
                if(max(l1, l2) > min(r1, r2)){
                        A = max(l1, l2) - min(r1, r2);
                        B = max(r1, r2) - min(l1, l2);
                } else{
                        k -= 1ll * n * (min(r1, r2) - max(l1, l2));
                        B = max(r1, r2) - min(l1, l2) - (min(r1, r2) - max(l1, l2));
                }
                if(k < 0){
                        cout << 0 << "\n";
                        continue;
                }
                long long res = 1e18;
                for(int i = 1; i <= n; i++){
                        long long cnt = 1ll * A * i;
                        long long have = 1ll * B * i;
                        cnt += min(have, k);
                        if(have < k){
                                cnt += 2 * (k - have);
                        }
                        res = min(res, cnt);
                }
                cout << res << '\n';
        }
}