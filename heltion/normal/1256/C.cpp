#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1200;
int c[maxn], b[maxn], a[maxn];
void no(){
    cout << "NO";
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, d;
    cin >> n >> m >> d;
    for(int i = 1; i <= m; i += 1) cin >> c[i];
    c[0] = 1;
    for(int i = 1; i <= m + 1; i += 1) b[i] = b[i - 1] + c[i - 1] - 1 + d;
    if(b[m + 1] < n + 1) no();
    cout << "YES\n";
    b[m + 1] = n + 1;
    for(int i = m; i >= 1; i -= 1) if(b[i] + c[i] > b[i + 1]) b[i] = b[i + 1] - c[i];
    for(int i = 1; i <= m; i += 1) for(int j = b[i]; j < b[i] + c[i]; j += 1) a[j] = i;
    for(int i = 1; i <= n; i += 1) cout << a[i] << " ";
    return 0;
}