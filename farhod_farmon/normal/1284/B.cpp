#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 1000011;

using namespace std;

int n;
int a[N];
int b[N];
int c[Q];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        vector < int > v;
        long long res = 0, X = 0, Y = 0;
        for(int i = 1; i <= n; i++){
                int k;
                cin >> k;
                v.resize(k);
                bool good = false;
                for(int j = 0; j < k; j++){
                        cin >> v[j];
                        if(j > 0 && v[j - 1] < v[j]){
                                good = true;
                        }
                }
                if(good){
                        X += 1;
                        i -= 1;
                        n -= 1;
                } else{
                        Y += 1;
                        a[i] = v[0];
                        b[i] = v.back();
                }
        }
        res = X * X + 2ll * X * Y;

        for(int i = 1; i <= n; i++){
                assert(a[i] >= b[i]);
                c[b[i]] += 1;
        }
        for(int i = 1; i < Q; i++){
                c[i] += c[i  - 1];
        }
        for(int i = 1; i <= n; i++){
                if(a[i] > 0){
                        res += c[a[i] - 1];
                }
        }
        cout << res << "\n";
}