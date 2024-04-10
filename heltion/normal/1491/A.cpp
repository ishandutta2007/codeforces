#include<bits/stdc++.h>
using namespace std;
using namespace std;
constexpr int maxn = 100000 + 1;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int n, q, cnt = 0;
    cin >> n >> q;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        cnt += a[i];
    }
    for(int t; q; q -= 1){
        cin >> t;
        if(t == 1){
            int x;
            cin >> x;
            cnt -= a[x];
            a[x] = 1 - a[x];
            cnt += a[x];
        }
        else{
            int k;
            cin >> k;
            cout << (cnt >= k) << "\n";
        }
    }
    return 0;
}