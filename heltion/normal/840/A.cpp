#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000;
int A[maxn], B[maxn], p[maxn], ans[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //(n + 1) / (k + 1)
    int m;
    cin >> m;
    for(int i = 0; i < m; i += 1) cin >> A[i];
    for(int i = 0; i < m; i += 1) cin >> B[i];
    for(int i = 0; i < m; i += 1) p[i] = i;
    sort(A, A + m);
    sort(p, p + m, [&](const int& x, const int& y){
        return B[x] > B[y];
    });
    for(int i = 0; i < m; i += 1) ans[p[i]] = A[i];
    for(int i = 0; i < m; i += 1) cout << ans[i] << " ";
    return 0;
}