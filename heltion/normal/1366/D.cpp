#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 10000000;
int p[maxn + 1], cp[maxn + 1], mp[maxn + 1], pn;
int d[2][maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 2; i <= maxn; i += 1){
        if(not mp[i]) p[pn ++] = mp[i] = i;
        for(int j = 0; j < pn; j += 1){
            int k = i * p[j];
            if(k > maxn) break;
            mp[k] = p[j];
            if(i % p[j] == 0) break;
        }
    }
    for(int i = 1, a, b; i <= n; i += 1){
        cin >> a;
        b = mp[a];
        while(a % b == 0) a /= b;
        if(a == 1) d[0][i] = d[1][i] = -1;
        else{
            d[0][i] = b;
            d[1][i] = a;
        }
    }
    for(int i = 1; i <= n; i += 1) cout << d[0][i] << " ";
    cout << "\n";
    for(int i = 1; i <= n; i += 1) cout << d[1][i] << " ";
}