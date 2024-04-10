#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1) cin >> a[i];
        int m = min_element(a + 1, a + n + 1) - a;
        if(m != 1){
            cout << n << "\n";
            cout << "1 " << m << " " << a[m] << " " << a[m] << "\n";
        }
        else cout << n - 1 << "\n";
        for(int i = 2; i <= n; i += 1) cout << 1 << " " << i << " " << a[m] << " " << a[m] + i - 1 << "\n";
    }
    return 0;
}