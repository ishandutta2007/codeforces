#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;
long long d[N][3];
vector < int > v[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 2; i <= n; i++){
                int x;
                cin >> x;
                v[x].push_back(i);
        }
        for(int i = n; i >= 1; i--){
                if(v[i].empty()){
                        d[i][2] = 1;
                        continue;
                }
                d[i][0] = 1;
                for(int j: v[i]){
                        d[i][2] = (d[i][2] * (d[j][0] + d[j][2]) + (d[i][1] + d[i][2]) * (d[j][1] + d[j][2])) % mod;
                        d[i][1] = (d[i][1] * (d[j][0] + d[j][2]) + d[i][0] * (d[j][1] + d[j][2])) % mod;
                        d[i][0] = d[i][0] * (d[j][0] + d[j][2]) % mod;
                }
        }
        cout << (d[1][0] + d[1][2]) % mod << "\n";
}