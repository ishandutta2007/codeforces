#include <bits/stdc++.h>

#define fi first
#define se second
#define pt pair < double, double >

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
                vector < int > a(n + 1, 0);
                vector < long long > s(n + 1, 0);
                int res = 1;
                for(int i = 0; i <= n; i++){
                        if(i < n){
                                cin >> a[i];
                        }
                        s[i] = - a[i];
                        if(i > 0){
                                s[i] -= s[i - 1];
                        }

                        if(s[i] > 0){
                                res = 0;
                        } else if(i == n){
                                res &= (s[i] == 0);
                        }
                }
                vector < long long > p0(n + 2, - 1e18), p1(n + 2, - 1e18);
                for(int i = n; i >= 0; i--){
                        p0[i] = p0[i + 1];
                        p1[i] = p1[i + 1];
                        if(i % 2){
                                p1[i] = max(p1[i], s[i]);
                        } else{
                                p0[i] = max(p0[i], s[i]);
                        }
                }
                for(int i = 1; i < n; i++){
                        int x = a[i - 1], y = a[i];
                        int good = 1;
                        good &= (s[i - 1] + x - y) <= 0;
                        good &= (s[i] - 2 * x + 2 * y) <= 0;
                        if(n % 2 == i % 2){
                                good &= (s[n] - 2 * x + 2 * y) == 0;
                        } else{
                                good &= (s[n] + 2 * x - 2 * y) == 0;
                        }
                        if(i % 2){
                                good &= (p1[i + 1] - 2 * x + 2 * y) <= 0;
                                good &= (p0[i + 1] + 2 * x - 2 * y) <= 0;
                        } else{
                                good &= (p0[i + 1] - 2 * x + 2 * y) <= 0;
                                good &= (p1[i + 1] + 2 * x - 2 * y) <= 0;
                        }
                        res |= good;
                        if(s[i - 1] > 0){
                                break;
                        }
                }
                cout << (res ? "YES" : "NO") << "\n";
        }
}