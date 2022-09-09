#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 540000;
LL m[maxn], pre[maxn], suf[maxn], a[maxn];
LL sum = 0;
stack<pair<LL, int>> sp;
void add(LL m){
    int cnt = 1;
    for(;not sp.empty() and sp.top().first >= m; sp.pop()){
        sum -= sp.top().first * sp.top().second;
        cnt += sp.top().second;
    }
    sp.push({m, cnt});
    sum += cnt * m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> m[i];
    for(int i = 1; i <= n; i += 1){
        add(m[i]);
        pre[i] = sum;
    }
    for(sum = 0; not sp.empty(); sp.pop());
    for(int i = n; i; i -= 1){
        add(m[i]);
        suf[i] = sum;
    }
    int ans = 1;
    for(int i = 1; i <= n; i += 1) if(pre[i] + suf[i] - m[i] > pre[ans] + suf[ans] - m[ans]) ans = i;
    a[ans] = m[ans];
    for(int i = ans - 1; i; i -= 1) a[i] = min(m[i], a[i + 1]);
    for(int i = ans + 1; i <= n; i += 1) a[i] = min(m[i], a[i - 1]);
    for(int i = 1; i <= n; i += 1) cout << a[i] << " ";
    return 0;
}