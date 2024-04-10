#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2010;

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
                vector<long long> a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                int cnt = 0;
                sort(a.begin(), a.end());
                int mx = 0;
                for(int i = 0; i < n; i++){
                        while(a[i] % 2 == 0){
                                a[i] /= 2;
                                cnt += 1;
                        }
                        if(a[i] > a[mx]){
                                mx = i;
                        }
                }
                for(int i = 0; i < cnt; i++){
                        a[mx] *= 2;
                }
                long long res = 0;
                for(auto x : a){
                        res += x;
                }
                cout << res << "\n";
        }
}