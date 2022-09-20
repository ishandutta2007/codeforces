#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 110119;

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
                cin >> n;
                vector < int > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                vector < long long > A(n, 0), B(n, 0);

                auto get = [&](int x)
                {
                        if(x <= 0 || x >= n - 1){
                                return 0;
                        }
                        return (a[x] > a[x - 1] && a[x] > a[x + 1]) | (a[x] < a[x - 1] && a[x] < a[x + 1]);
                };

                for(int i = 2; i < n; i++){
                        A[i] = A[i - 1] + get(i - 1);
                }
                for(int i = n - 3; i >= 0; i--){
                        B[i] = B[i + 1] + get(i + 1);
                }
                int res = A.back();
                vector < int > v;
                for(int i = 0; i < n; i++){
                        v.clear();
                        int cnt = 0;
                        if(i > 0){
                                cnt += A[i - 1];
                                v.push_back(a[i - 1] - 1);
                                v.push_back(a[i - 1] + 1);
                                v.push_back(a[i - 1]);
                        }
                        if(i + 1 < n){
                                cnt += B[i + 1];
                                v.push_back(a[i + 1] - 1);
                                v.push_back(a[i + 1] + 1);
                                v.push_back(a[i + 1]);
                        }
                        int was = a[i];
                        for(int x: v){
                                a[i] = x;
                                res = min(res, cnt + get(i - 1) + get(i) + get(i + 1));
                        }
                        a[i] = was;
                }
                cout << res << "\n";
        }
}