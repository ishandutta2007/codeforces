#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
int id[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i += 1){
        cin >> id[i];
        if(i >= k){
            cout << id[k];
            return 0;
        }
        k -= i;
    }
    return 0;
}