#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1000000007;

using namespace std;

int n;
long long k;
long long a[N];
long long b[N];
long long f[N];
vector < int > v[N];

bool can(long long m)
{
        for(int i = 0; i <= k; i++){
                v[i].clear();
        }
        for(int i = 1; i <= n; i++){
                f[i] = a[i];
                v[min(k, f[i] / b[i])].push_back(i);
        }
        for(int i = 1, j = 0; i < k; i++){
                while(j < k && v[j].empty()){
                        j++;
                }
                if(j >= k){
                        return true;
                }
                int x = v[j].back();
                v[j].pop_back();
                f[x] += m;
                v[min(k, f[x] / b[x])].push_back(x);
                while(j < k && v[j].empty()){
                        j++;
                }
                if(j < i){
                        return false;
                }
        }
        return true;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
        }
        long long l = 0, r = 1e18;
        while(l < r){
                long long m = (l + r) / 2;
                if(can(m)){
                        r = m;
                }
                else{
                        l = m + 1;
                }
        }
        if(l > 1e17){
                l = -1;
        }
        cout << l << "\n";
}