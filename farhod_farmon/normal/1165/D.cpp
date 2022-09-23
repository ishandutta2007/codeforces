#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                int n;
                cin >> n;
                vector < long long > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                sort(a.begin(), a.end());
                long long res = 1, bad = 1e12;
                for(int i = 0; i < n; i++){
                        res = res * a[i] / __gcd(res, 1ll * a[i]);
                        if(res > bad){
                                break;
                        }
                }
                if(res == a.back()){
                        res *= a[0];
                }
                if(res > bad){
                        cout << -1 << "\n";
                        continue;
                }
                vector < long long > v;
                for(long long i = 2; i * i <= res; i++){
                        if(res % i == 0){
                                v.push_back(i);
                                if(i * i != res){
                                        v.push_back(res / i);
                                }
                        }
                }

                sort(v.begin(), v.end());

                if(a != v){
                        cout << -1 << "\n";
                } else{
                        cout << res << "\n";
                }
        }
}