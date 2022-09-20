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
                vector<int> a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }

                int res = 0;
                for(int i = 0, j = 1; i < n; i++){
                        if(i + 1 < n && a[i] == a[i + 1]){
                                j += 1;
                                continue;
                        }
                        int cnt = j, last = i;
                        while(true){
                                int x = lower_bound(a.begin() + last + 1, a.end(), 2 * a[last] - a[i]) - a.begin();
                                if(x == a.size()){
                                        break;
                                }
                                last = x;
                                cnt += 1;
                        }
                        j = 1;
                        res = max(res, cnt);
                }
                cout << n - res << "\n";
        }
}