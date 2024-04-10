#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000010;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                long long k;
                cin >> n >> k;
                vector < long long > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                sort(a.begin(), a.end());
                long long g = a[1] - a[0];
                for(int i = 2; i < n; i++){
                        g = __gcd(g, a[i] - a[i - 1]);
                }
                if(abs(a[0] - k) % g == 0){
                        cout << "YES" << "\n";
                } else{
                        cout << "NO" << "\n";
                }
        }
}