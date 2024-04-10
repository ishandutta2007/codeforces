#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
int a[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        priority_queue<pair<int, int>> q;
        q.push({n, -1});
        for(int i = 1; i <= n; i += 1){
            auto [x, L] = q.top();
            q.pop();
            L = -L;
            int R = L + x - 1;
            int M = (L + R) >> 1;
            a[M] = i;
            if(L < M) q.push({M - L, - L});
            if(R > M) q.push({R - M, - M - 1});
        }
        for(int i = 1; i <= n; i += 1) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}