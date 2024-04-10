#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 55;
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

        vector < long long > p(55);
        p[0] = p[1] = p[2] = 1;
        for(int i = 3; i < p.size(); i++){
                p[i] = 2 * p[i - 1];
        }

        int T;
        cin >> T;
        while(T--){
                long long a, b, m;
                cin >> a >> b >> m;
                if(a == b){
                        cout << 1 << " " << a << "\n";
                        continue;
                }
                vector < long long > res = {-1};
                for(int k = 2; k <= 50; k++){
                        if(p[k] > b / a || p[k] * a > b){
                                continue;
                        }
                        vector < long long > v(k, 0);
                        v[0] = a;
                        long long g = b - p[k] * a;
                        for(int i = 1; i < k; i++){
                                v[i] = 1;
                                g -= p[k - i];
                        }
                        for(int i = 1; i < k; i++){
                                long long l = 0, r = m - 1;
                                while(l < r){
                                        long long m = (l + r) / 2 + 1;
                                        if(p[k - i] > g / m || p[k - i] * m > g){
                                                r = m - 1;
                                        } else{
                                                l = m;
                                        }
                                }
                                v[i] += l;
                                g -= l * p[k - i];

                                if(g <= 0){
                                        break;
                                }
                        }
                        if(g != 0){
                                continue;
                        }
                        res = v;
                        long long sum = res[0];
                        for(int i = 1; i < res.size(); i++){
                                res[i] += sum;
                                sum += res[i];
                        }
                        break;
                }
                if(res[0] == -1){
                        cout << -1 << "\n";
                } else{
                        cout << res.size() << " ";
                        for(auto x: res){
                                cout << x << " ";
                        }
                        cout << "\n";
                }
        }
}