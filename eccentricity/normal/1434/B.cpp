#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 * 2 + 1;
using LL = long long;
char t[maxn][2];
int a[maxn], p[maxn], L[maxn], ans[maxn];
void no(){
    cout << "NO";
    exit(0);
}
int getL(int u){
    return L[u] == u ? u : L[u] = getL(L[u]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= 2 * n; i += 1){
        cin >> t[i];
        if(*t[i] == '-'){
            cin >> a[i];
            p[a[i]] = i;
        }
        L[i] = i;
    }
    for(int i = 1; i <= n; i += 1){
        int j = getL(p[i] - 1);
        if(*t[j] != '+') no();
        ans[j] = i;
        L[p[i]] = p[i] - 1;
        L[j] = j - 1;
    }
    cout << "YES\n";
    for(int i = 1; i <= 2 * n; i += 1)
        if(*t[i] == '+') cout << ans[i] << " ";
    return 0;
}