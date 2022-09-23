#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 1000011;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        long long inf = 1e18;

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n), b(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                for(int i = 0; i < n; i++){
                        cin >> b[i];
                }
                long long res = 0;
                for(int h = 0; h < 2; h++){
                        vector < long long > d(2, inf);
                        if(h == 0){
                                d[0] = 0;
                        } else{
                                d[1] = -a[0];
                        }
                        for(int i = 1; i < n; i++){
                                vector < long long > f(2, inf);
                                for(int x = 0; x < 2; x++){
                                        for(int y = 0; y < 2; y++){
                                                long long cur = d[x];
                                                if(x || y){
                                                        cur += b[i - 1];
                                                }
                                                if(y){
                                                        cur -= a[i];
                                                }
                                                f[y] = min(f[y], cur);
                                        }
                                }
                                d = f;
                        }
                        for(int x = 0; x < 2; x++){
                                if(h || x){
                                        d[x] += b[n - 1];
                                }
                                res = min(res, d[x]);
                        }
                }
                cout << (res < 0 ? "NO" : "YES") << "\n";
        }
}