#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 55;
const long long mod = 998244353;

using namespace std;

int g(int n)
{
        return n ^ (n >> 1);
}

int n;
int a[N];
vector < int > v, t;

int make(int k)
{
        int res = 0;
        v.resize(k);
        t.resize(k);
        for(int i = 0; i < k; i++){
                v[i] = t[i] = 0;
        }
        for(int i = 1; i <= n; i++){
                if(a[i] >= (1 << k)){
                        continue;
                }
                int x = a[i];
                for(int j = 0; j < k; j++){
                        if(x & (1 << j)){
                                if(v[j]){
                                        x ^= v[j];
                                } else{
                                        res += 1;
                                        v[j] = x;
                                        t[j] = a[i];
                                        break;
                                }
                        }
                }
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int res = 22;
        while(make(res) != res){
                res -= 1;
        }
        make(res);
        cout << res << "\n";
        for(int i = 0; i < (1 << res); i++){
                int cur = 0;
                for(int j = 0; j < res; j++){
                        if(g(i) & (1 << j)){
                                cur ^= t[j];
                        }
                }
                cout << cur << " ";
        }
}