#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 50005;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                int n, x;
                cin >> n >> x;
                vector < int > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                sort(a.begin(), a.end());
                reverse(a.begin(), a.end());

                int res = 0;
                long long sum = 0;
                while(res < n){
                        sum += a[res];
                        res += 1;
                        if(1ll * res * x > sum){
                                res -= 1;
                                break;
                        }
                }

                cout << res << "\n";
        }
}