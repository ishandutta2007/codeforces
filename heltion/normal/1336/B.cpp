#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
int n[3];
LL a[3][maxn];
bool check(int* i){
    for(int j = 0; j < 3; j += 1) if(i[j] == n[j]) return false;
    return true;
}
LL square(LL x){
    return x * x;
}
LL f(int* p){
    int i[3] = {};
    LL res = LLONG_MAX;
    for(; check(i); i[p[1]] += 1){
        while(check(i) and i[p[0]] + 1 < n[p[0]] and a[p[0]][i[p[0]] + 1] <= a[p[1]][i[p[1]]]) i[p[0]] += 1;
        while(check(i) and a[p[2]][i[p[2]]] < a[p[1]][i[p[1]]]) i[p[2]] += 1;
        if(check(i))
            res = min(square(a[0][i[0]] - a[1][i[1]]) + square(a[0][i[0]] - a[2][i[2]]) + square(a[1][i[1]] - a[2][i[2]]), res);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        for(int i = 0; i < 3; i += 1) cin >> n[i];
        for(int i = 0; i < 3; i += 1){
            for(int j = 0; j < n[i]; j += 1) cin >> a[i][j];
            sort(a[i], a[i] + n[i]);
        }
        LL ans = LLONG_MAX;
        int p[] = {0, 1, 2};
        do ans = min(f(p), ans);
        while(next_permutation(p, p + 3));
        cout << ans << "\n";
    }
    return 0;
}