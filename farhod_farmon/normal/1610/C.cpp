#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int Q = 2 * N;

using namespace std;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector<int> a(n), b(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i] >> b[i];
                }
                int l = 0, r = n;
                while(l < r){
                        int m = (l + r) / 2 + 1;
                        int cnt = 0;
                        for(int i = 0; i < n && cnt < m; i++){
                                if(b[i] >= cnt && a[i] >= m - cnt - 1){
                                        cnt += 1;
                                }
                        }
                        if(cnt == m){
                                l = m;
                        } else{
                                r = m - 1;
                        }
                }
                cout << l << "\n";
        }
}