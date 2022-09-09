#include <bits/stdc++.h>
using namespace std;
using LL = long long;
pair<LL, LL> linear_congruence_equations(const vector<pair<LL, LL>>& p){
    function<LL(LL,LL,LL&,LL&)> exgcd = [&](LL a, LL b, LL& x, LL& y){
        if(not b) return x = 1, y = 0, a;
        LL d = exgcd(b, a % b, x, y), t = x;
        return x = y, y = t - a / b * y, d;
    };
    __int128 A = 1, B = 0;
    for(auto [a, b] : p){
        LL x, y, d = exgcd(A, a, x, y);
        if((b - B) % d) return {-1, -1};
        B += ((b - B) * x / d) % (a / d) * A;
        A = A / d * a;
        B = (B % A + A) % A;
    }
    return {A, B};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    LL k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    vector<int> A(2 * max(n, m) + 1, -1), B(2 * max(n, m) + 1, -1);
    for(int i = 0; i < n; i += 1){
        cin >> a[i];
        A[a[i]] = i;
    }
    for(int i = 0; i < m; i += 1){
        cin >> b[i];
        B[b[i]] = i;
    }
    vector<LL> rm;
    for(int i = 1; i <= 2 * max(n, m); i += 1)
        if(A[i] != -1 and B[i] != -1){
            auto p = linear_congruence_equations({{n, A[i]}, {m, B[i]}});
            if(p.first != -1)
                rm.push_back(p.second);
        }
    LL d = (LL)n * m / __gcd(n, m);
    LL per = d - rm.size();
    LL L = 1, R = 1E18;
    while(L < R){
        LL M = L + (R - L) / 2;
        LL pk = M / d * per;
        LL x = M % d;
        pk += x;
        for(LL i : rm) if(i < x) pk -= 1;
        if(pk >= k) R = M;
        else L = M + 1;
    }
    cout << L;
    return 0;
}