#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 1;
int p[maxn], q[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        cin >> p[i];
        q[p[i]] = i;
    }
    for(int i = 1; i <= n; i += 1)
        if(p[i] != i){
            ans ^= 1;
            int j = q[i];
            swap(q[p[i]], q[p[j]]);
            swap(p[i], p[j]);
        }
    cout << (ans == (n & 1) ? "Petr" : "Um_nik");
    return 0;
}