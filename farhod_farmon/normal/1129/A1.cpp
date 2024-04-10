#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,sse4.1,sse4.2,sse4a,xsave")

#define fi first
#define se second

const int N = 5050;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int f[N];
vector < int > v[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int q;
        cin >> n >> q;
        for(int i = 1; i <= q; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
        }
        for(int i = 1; i <= n; i++){
                f[i] = -1e9;
                if(v[i].empty()){
                        continue;
                }
                f[i] = 1e9;
                for(int x: v[i]){
                        int g = x - i;
                        if(g < 0){
                                g += n;
                        }
                        f[i] = min(f[i], g);
                }
                f[i] += n * (v[i].size() - 1);
        }
        for(int i = 1; i <= n; i++){
                int res = 0;
                for(int j = 0; j < n; j++){
                        int h = (i + j - 1) % n + 1;
                        res = max(res, f[h] + j);
                }
                cout << res << " ";
        }
}