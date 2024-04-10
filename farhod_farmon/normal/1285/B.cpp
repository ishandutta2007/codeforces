#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                int n;
                cin >> n;
                vector < int > a(n);
                long long sum = 0;
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        sum += a[i];
                }
                long long res = 0, cur = 0;
                for(int i = 0; i < n - 1; i++){
                        cur = max(0ll, cur);
                        cur += a[i];
                        res = max(res, cur);
                }
                cur = 0;
                for(int i = 1; i < n; i++){
                        cur = max(0ll, cur);
                        cur += a[i];
                        res = max(res, cur);
                }
                if(res >= sum){
                        cout << "NO" << "\n";
                } else{
                        cout << "YES" << "\n";
                }
        }
}